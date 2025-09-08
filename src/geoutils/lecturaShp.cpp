#include "ogr_spatialref.h"
#include "ogrsf_frmts.h"
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Función que obtiene el bounding box
std::vector<double> sptBbox(const std::string &path) {
  std::vector<double> res;

  GDALAllRegister();
  GDALDataset *dataset = (GDALDataset *)GDALOpenEx(path.c_str(), GDAL_OF_VECTOR,
                                                   nullptr, nullptr, nullptr);
  if (!dataset)
    return res;

  OGRLayer *layer = dataset->GetLayer(0);
  if (!layer) {
    GDALClose(dataset);
    return res;
  }

  OGREnvelope bbox;
  if (layer->GetExtent(&bbox) == OGRERR_NONE)
    res = {bbox.MinX, bbox.MinY, bbox.MaxX, bbox.MaxY};

  GDALClose(dataset);
  return res;
}

// Función que transforma las coordenadas
void sptTransform(std::vector<double> &bbox, OGRSpatialReference *srcSRS,
                  int CRS) {
  if (bbox.empty() || !srcSRS || CRS == 0)
    return;

  OGRSpatialReference dstSRS;
  dstSRS.importFromEPSG(CRS);

  OGRCoordinateTransformation *coordTrans =
      OGRCreateCoordinateTransformation(srcSRS, &dstSRS);
  if (!coordTrans)
    return;

  double minX = bbox[0], minY = bbox[1];
  double maxX = bbox[2], maxY = bbox[3];

  coordTrans->Transform(1, &minX, &minY);
  coordTrans->Transform(1, &maxX, &maxY);

  bbox[0] = minX;
  bbox[1] = minY;
  bbox[2] = maxX;
  bbox[3] = maxY;

  OGRCoordinateTransformation::DestroyCT(coordTrans);
}

// Struct para resultados
struct bbox {
  std::vector<double> limits;
  std::string crsWKT;
};

// Función wrapper
bbox getBBox(const std::string &path, int CRS = 0) {
  bbox res;
  res.limits = sptBbox(path);
  if (res.limits.empty())
    return res;

  GDALAllRegister();
  GDALDataset *dataset = (GDALDataset *)GDALOpenEx(path.c_str(), GDAL_OF_VECTOR,
                                                   nullptr, nullptr, nullptr);
  if (!dataset)
    return res;

  OGRLayer *layer = dataset->GetLayer(0);
  OGRSpatialReference *srcSRS = layer->GetSpatialRef();

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

  int res = sqrt(n);
  if (res >= n)
    return {res, res};

  int res2 = n / res;
  if (res * res2 < n)
    return {res, res2 + 1};
  return {res, res2};
}

struct GridXY {
  std::vector<double> x;
  std::vector<double> y;
};

GridXY sptGrid(const std::string &path, const int &n, int &crs) {
  GridXY res;
  bbox recorte = getBBox(path, crs);
  if (recorte.limits.empty())
    return res;

  std::array<int, 2> shape = findMat(n);
  int row = shape[0];
  int col = shape[1];

  size_t totalPoints = static_cast<size_t>(row) * static_cast<size_t>(col);
  res.x.resize(totalPoints);
  res.y.resize(totalPoints);

  double stpX = (row > 1) ? (recorte.limits[2] - recorte.limits[0]) /
                                static_cast<double>(row - 1)
                          : 0.0;
  double stpY = (col > 1) ? (recorte.limits[3] - recorte.limits[1]) /
                                static_cast<double>(col - 1)
                          : 0.0;

  size_t idx = 0;
  for (int i = 0; i < row; ++i) {
    double x = recorte.limits[0] + i * stpX;
    for (int j = 0; j < col; ++j) {
      double y = recorte.limits[1] + j * stpY;
      res.x[idx] = x;
      res.y[idx] = y;
      ++idx;
    }
  }

  return res;
}

// Main
int main() {
  std::string path = "/home/xdsamubx/miniconda3/envs/cenv/cpp-scripts/data/"
                     "poligonos-localidades.shp";
  int crs = 4326; // EPSG deseado
  int n = 10000;  // número de puntos aproximado

  GridXY grid = sptGrid(path, n, crs);

  std::cout << "Grilla generada: " << grid.x.size() << " puntos\n";

  // Mostrar los primeros 10 puntos como prueba
  for (size_t i = 0; i < grid.x.size(); ++i) {
    std::cout << "(" << grid.x[i] << ", " << grid.y[i] << ")\n";
  }
  return 0;
}
