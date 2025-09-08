
#include "ogrsf_frmts.h"
#include <geos_c.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

// -------------------- Structs --------------------
struct BBox {
  std::vector<double> limits; // {minX, minY, maxX, maxY}
  std::string crsWKT;
};

struct GridXY {
  std::vector<double> x;
  std::vector<double> y;
};

// RAII para OGRCoordinateTransformation
struct OCTDeleter {
  void operator()(OGRCoordinateTransformation *ct) const {
    if (ct)
      OCTDestroyCoordinateTransformation(ct);
  }
};

// -------------------- Utilidades --------------------
std::vector<double> sptBbox(const std::string &path) {
  std::vector<double> res;
  GDALDataset *dataset = (GDALDataset *)GDALOpenEx(path.c_str(), GDAL_OF_VECTOR,
                                                   nullptr, nullptr, nullptr);
  if (!dataset) {
    std::cerr << "[sptBbox] No se pudo abrir: " << path << "\n";
    return res;
  }

  OGRLayer *layer = dataset->GetLayer(0);
  if (!layer) {
    std::cerr << "[sptBbox] La capa 0 no existe.\n";
    GDALClose(dataset);
    return res;
  }

  // Fuerza el cálculo por si no hay extent precalculado
  OGREnvelope bbox;
  if (layer->GetExtent(&bbox, TRUE) == OGRERR_NONE) {
    res = {bbox.MinX, bbox.MinY, bbox.MaxX, bbox.MaxY};
  } else {
    std::cerr << "[sptBbox] No fue posible obtener el extent.\n";
  }

  GDALClose(dataset);
  return res;
}

void sptTransform(std::vector<double> &bbox, const OGRSpatialReference *srcSRS,
                  int CRS) {
  if (bbox.size() != 4 || !srcSRS || CRS <= 0)
    return;

  OGRSpatialReference dstSRS;
  dstSRS.importFromEPSG(CRS);

  std::unique_ptr<OGRCoordinateTransformation, OCTDeleter> coordTrans(
      OGRCreateCoordinateTransformation(srcSRS, &dstSRS));
  if (!coordTrans) {
    std::cerr << "[sptTransform] No se pudo crear la transformación.\n";
    return;
  }

  double xs[4] = {bbox[0], bbox[2], bbox[0], bbox[2]};
  double ys[4] = {bbox[1], bbox[1], bbox[3], bbox[3]};
  if (!coordTrans->Transform(4, xs, ys)) {
    std::cerr << "[sptTransform] Falló Transform en vértices del BBOX.\n";
    return;
  }

  bbox[0] = *std::min_element(xs, xs + 4);
  bbox[1] = *std::min_element(ys, ys + 4);
  bbox[2] = *std::max_element(xs, xs + 4);
  bbox[3] = *std::max_element(ys, ys + 4);
}

BBox getBBox(const std::string &path, int CRS = 0) {
  BBox res;
  res.limits = sptBbox(path);
  if (res.limits.empty())
    return res;

  GDALDataset *dataset = (GDALDataset *)GDALOpenEx(path.c_str(), GDAL_OF_VECTOR,
                                                   nullptr, nullptr, nullptr);
  if (!dataset)
    return res;

  OGRLayer *layer = dataset->GetLayer(0);
  if (!layer) {
    std::cerr << "[getBBox] La capa 0 no existe.\n";
    GDALClose(dataset);
    return res;
  }
  OGRSpatialReference *srcSRS = layer->GetSpatialRef();

  if (srcSRS) {
    char *wkt = nullptr;
    srcSRS->exportToWkt(&wkt);
    if (wkt) {
      // opcional: guardar WKT fuente (antes de reproyectar)
      CPLFree(wkt);
    }
  } else {
    std::cerr << "[getBBox] La capa no tiene SRS definido.\n";
  }

  if (CRS > 0 && srcSRS) {
    sptTransform(res.limits, srcSRS, CRS);
    OGRSpatialReference dstSRS;
    dstSRS.importFromEPSG(CRS);
    char *wkt = nullptr;
    dstSRS.exportToWkt(&wkt);
    if (wkt) {
      res.crsWKT = std::string(wkt);
      CPLFree(wkt);
    }
  } else if (srcSRS) {
    char *wkt = nullptr;
    srcSRS->exportToWkt(&wkt);
    if (wkt) {
      res.crsWKT = std::string(wkt);
      CPLFree(wkt);
    }
  } else {
    res.crsWKT = "CRS desconocido";
  }

  GDALClose(dataset);
  return res;
}

std::array<int, 2> findMat(const int &n) {
  if (n <= 0)
    throw std::invalid_argument("n debe ser mayor a 0");
  int res = static_cast<int>(std::sqrt(static_cast<double>(n)));
  int res2 = n / res;
  if (res * res2 < n)
    res2++;
  return {res, res2};
}

GridXY gridGen(const BBox &recorte, int n) {
  GridXY res;
  if (recorte.limits.size() != 4)
    return res;

  std::array<int, 2> shape = findMat(n);
  int row = shape[0], col = shape[1];
  size_t totalPoints = static_cast<size_t>(row) * static_cast<size_t>(col);

  res.x.reserve(totalPoints);
  res.y.reserve(totalPoints);

  const double stpX =
      (row > 1) ? (recorte.limits[2] - recorte.limits[0]) / (row - 1) : 0.0;
  const double stpY =
      (col > 1) ? (recorte.limits[3] - recorte.limits[1]) / (col - 1) : 0.0;

  for (int i = 0; i < row; ++i) {
    const double x = recorte.limits[0] + i * stpX;
    for (int j = 0; j < col; ++j) {
      const double y = recorte.limits[1] + j * stpY;
      res.x.push_back(x);
      res.y.push_back(y);
    }
  }
  return res;
}

// -------------------- Filtrado con GEOS --------------------
void filterGrid(GridXY &grid, const std::string &path, int gridEPSG) {
  if (grid.x.size() != grid.y.size())
    return;

  GEOSContextHandle_t hGeosCtx = GEOS_init_r();
  if (!hGeosCtx) {
    std::cerr << "[filterGrid] Error al inicializar GEOS.\n";
    return;
  }

  GDALDataset *dataset = (GDALDataset *)GDALOpenEx(path.c_str(), GDAL_OF_VECTOR,
                                                   nullptr, nullptr, nullptr);
  if (!dataset) {
    std::cerr << "[filterGrid] No se pudo abrir dataset.\n";
    GEOS_finish_r(hGeosCtx);
    return;
  }
  OGRLayer *layer = dataset->GetLayer(0);
  if (!layer) {
    std::cerr << "[filterGrid] La capa 0 no existe.\n";
    GDALClose(dataset);
    GEOS_finish_r(hGeosCtx);
    return;
  }

  // Transformación al CRS de la malla si hace falta
  OGRSpatialReference *srcSRS = layer->GetSpatialRef();
  OGRSpatialReference dstSRS;
  if (gridEPSG > 0)
    dstSRS.importFromEPSG(gridEPSG);

  std::unique_ptr<OGRCoordinateTransformation, OCTDeleter> toGrid;
  if (gridEPSG > 0 && srcSRS && !srcSRS->IsSame(&dstSRS)) {
    toGrid.reset(OGRCreateCoordinateTransformation(srcSRS, &dstSRS));
    if (!toGrid) {
      std::cerr << "[filterGrid] No se pudo crear transformación a EPSG:"
                << gridEPSG << "\n";
      GDALClose(dataset);
      GEOS_finish_r(hGeosCtx);
      return;
    }
  }

  // Cargar y (si corresponde) transformar polígonos a gridEPSG
  std::vector<GEOSGeometry *> polygons;
  polygons.reserve(1024);

  GEOSWKBReader *reader = GEOSWKBReader_create_r(hGeosCtx);

  layer->ResetReading();
  OGRFeature *feature;
  while ((feature = layer->GetNextFeature()) != nullptr) {
    OGRGeometry *ogrGeom = feature->GetGeometryRef();
    if (ogrGeom) {
      std::unique_ptr<OGRGeometry> geomCopy(ogrGeom->clone());
      if (toGrid) {
        if (geomCopy->transform(toGrid.get()) != OGRERR_NONE) {
          OGRFeature::DestroyFeature(feature);
          continue;
        }
      }

      const int wkbSize = geomCopy->WkbSize();
      std::vector<unsigned char> wkb(wkbSize);
      geomCopy->exportToWkb(wkbNDR, wkb.data());

      GEOSGeometry *poly =
          GEOSWKBReader_read_r(hGeosCtx, reader, wkb.data(), wkbSize);
      if (poly)
        polygons.push_back(poly);
    }
    OGRFeature::DestroyFeature(feature);
  }
  GEOSWKBReader_destroy_r(hGeosCtx, reader);
  GDALClose(dataset);

  if (polygons.empty()) {
    std::cerr << "[filterGrid] No se leyeron polígonos del shapefile.\n";
    GEOS_finish_r(hGeosCtx);
    return;
  }

  // Índice espacial: mantener vivas las envolventes
  std::vector<GEOSGeometry *> envelopes;
  envelopes.reserve(polygons.size());

  GEOSSTRtree *index = GEOSSTRtree_create_r(hGeosCtx, 10);
  for (GEOSGeometry *poly : polygons) {
    GEOSGeometry *env = GEOSEnvelope_r(hGeosCtx, poly);
    envelopes.push_back(env);
    GEOSSTRtree_insert_r(hGeosCtx, index, env, poly); // item: poly
  }

  // Preparar geometrías para acelerar Covers
  std::unordered_map<const GEOSGeometry *, const GEOSPreparedGeometry *> prep;
  prep.reserve(polygons.size());
  for (GEOSGeometry *poly : polygons) {
    prep[poly] = GEOSPrepare_r(hGeosCtx, poly);
  }

  // Filtrado
  GridXY filteredGrid;
  filteredGrid.x.reserve(grid.x.size());
  filteredGrid.y.reserve(grid.y.size());

  for (size_t i = 0; i < grid.x.size(); ++i) {
    GEOSCoordSequence *cs = GEOSCoordSeq_create_r(hGeosCtx, 1, 2);
    GEOSCoordSeq_setX_r(hGeosCtx, cs, 0, grid.x[i]);
    GEOSCoordSeq_setY_r(hGeosCtx, cs, 0, grid.y[i]);
    GEOSGeometry *pt = GEOSGeom_createPoint_r(hGeosCtx, cs);

    std::vector<void *> candidates;
    candidates.reserve(16);
    GEOSSTRtree_query_r(
        hGeosCtx, index, pt,
        [](void *item, void *userdata) {
          auto *vec = static_cast<std::vector<void *> *>(userdata);
          vec->push_back(item);
        },
        &candidates);

    bool inside = false;
    for (void *c : candidates) {
      const GEOSGeometry *poly = static_cast<const GEOSGeometry *>(c);
      auto it = prep.find(poly);
      if (it != prep.end()) {
        if (GEOSPreparedCovers_r(hGeosCtx, it->second, pt)) {
          inside = true;
          break;
        }
      } else {
        if (GEOSCovers_r(hGeosCtx, poly, pt)) {
          inside = true;
          break;
        }
      }
    }

    GEOSGeom_destroy_r(hGeosCtx, pt);

    if (inside) {
      filteredGrid.x.push_back(grid.x[i]);
      filteredGrid.y.push_back(grid.y[i]);
    }
  }

  grid.x.swap(filteredGrid.x);
  grid.y.swap(filteredGrid.y);

  // Limpieza
  for (auto &kv : prep)
    GEOSPreparedGeom_destroy_r(hGeosCtx, kv.second);
  for (auto *env : envelopes)
    GEOSGeom_destroy_r(hGeosCtx, env);
  for (auto *poly : polygons)
    GEOSGeom_destroy_r(hGeosCtx, poly);
  GEOSSTRtree_destroy_r(hGeosCtx, index);
  GEOS_finish_r(hGeosCtx);
}

// -------------------- Wrapper --------------------
GridXY geoGrid(const std::string &shpPath, int n, int CRS = 0,
               bool intern = false) {
  BBox recorte = getBBox(shpPath, CRS);
  if (recorte.limits.size() != 4) {
    std::cerr << "[generateGrid] BBOX vacío. Revisa la ruta o el shapefile.\n";
    return {};
  }

  std::cerr << "BBOX final: [" << recorte.limits[0] << ", " << recorte.limits[1]
            << ", " << recorte.limits[2] << ", " << recorte.limits[3] << "]\n";

  GridXY grid = gridGen(recorte, n);
  if (intern)
    filterGrid(grid, shpPath, CRS);
  return grid;
}

// -------------------- Main --------------------
int main() {
  GDALAllRegister();

  // Ajusta esta ruta a tu dataset
  std::string path = "/home/xdsamubx/miniconda3/envs/cenv/cpp-scripts/data/"
                     "poligonos-localidades.shp";

  int crs =
      3116; // Bogotá. Si el .shp NO tiene SRS, usa crs=0 (sin reproyección).
  int n = 50000;
  bool intern = false; // true: recorta al shape; false: usa todo el bbox

  // ¡OJO! Pasa crs antes de intern:
  GridXY grid = geoGrid(path, n, crs, intern);

  std::cout << "Puntos finales: " << grid.x.size() << "\n";
  for (size_t i = 0; i < std::min(grid.x.size(), size_t(10)); ++i)
    std::cout << "(" << grid.x[i] << ", " << grid.y[i] << ")\n";

  return 0;
}
