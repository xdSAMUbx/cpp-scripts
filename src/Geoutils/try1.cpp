#include "ogrsf_frmts.h"
#include <iostream>

int main() {
  GDALAllRegister();

  const char *filename = "/home/xdsamubx/miniconda3/envs/cenv/cpp-scripts/data/"
                         "poligonos-localidades.shp";
  GDALDataset *dataset = (GDALDataset *)GDALOpenEx(filename, GDAL_OF_VECTOR,
                                                   nullptr, nullptr, nullptr);
  if (!dataset) {
    std::cerr << "No se pudo abrir el shapefile\n";
    return 1;
  }

  OGRLayer *layer = dataset->GetLayer(0);
  OGREnvelope bbox;

  OGRErr err = layer->GetExtent(&bbox);
  if (err != OGRERR_NONE) {
    std::cerr << "Error al obtener bounding box!\n";
    GDALClose(dataset);
    return 1;
  }

  std::cout << "Bounding Box:\n";
  std::cout << "Xmin: " << bbox.MinX << ", Xmax: " << bbox.MaxX << "\n";
  std::cout << "Ymin: " << bbox.MinY << ", Ymax: " << bbox.MaxY << "\n";

  GDALClose(dataset);
  return 0;
}
