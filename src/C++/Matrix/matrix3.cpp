#include <array>
#include <cmath>
#include <iostream>
#include <vector>
// ------------------------------------------------------------------------
// ---------------------------------- STRUCTS -----------------------------
// ------------------------------------------------------------------------
template <typename T> struct Point {
  T x, y;
  // Esto es un constructor instrinseco
  Point() {
    x = 0;
    y = 0;
  }
  // Esto es un constructor con parametros
  Point(T _x, T _y) {
    x = _x;
    y = _y;
  };
  void shwPoint() { std::cout << "(" << x << ", " << y << ")" << std::endl; }
};

template <typename T> struct gridXY {
  std::vector<T> x;
  std::vector<T> y;

  void shwGrid() {
    for (size_t i = 0; i < x.size(); i++) {
      std::cout << "(" << x[i] << ", " << y[i] << ")\n";
    }
  }
};
// ---------------------------------------------------------------------------
// -------------------------- FUNCIONES --------------------------------------
// ---------------------------------------------------------------------------
std::array<size_t, 2> findMat(const size_t &n) {

  size_t rows = static_cast<size_t>(floor(sqrt(static_cast<long double>(n))));
  if (rows == 0)
    rows = 1;

  size_t cols = (n + rows - 1) / rows;
  return {rows, cols};
}

gridXY<double> gridGen(const std::array<double, 4> &bbox, const size_t &n) {
  gridXY<double> res;
  std::array<size_t, 2> shape = findMat(n);
  if (!(bbox[2] > bbox[0] && bbox[3] > bbox[1]))
    throw std::invalid_argument("BBox invalido: minX<maxX y minY<maxY");
  // bbox = {minX, minY, maxX, maxY};
  const size_t nx = shape[0];
  const size_t ny = shape[1];
  double stpX =
      (nx > 1) ? (bbox[2] - bbox[0]) / static_cast<double>(nx - 1) : 0.0;
  double stpY =
      (ny > 1) ? (bbox[3] - bbox[1]) / static_cast<double>(ny - 1) : 0.0;
  res.x.reserve(nx * ny);
  res.y.reserve(nx * ny);
  for (size_t i = 0; i < nx; i++) {
    double x = bbox[0] + static_cast<double>(i) * stpX;
    for (size_t j = 0; j < ny; j++) {
      double y = bbox[1] + static_cast<double>(j) * stpY;
      res.x.emplace_back(x);
      res.y.emplace_back(y);
    }
  }
  return res;
}

// gridXY<double> gridGen(const double &area, const size_t &n) {}

int main() {
  Point p1(1, 2);
  p1.shwPoint();
  std::array<double, 4> limits = {1.0, 1., 10., 10.};
  gridXY<double> grilla1 = gridGen(limits, 100);
  grilla1.shwGrid();
  return 0;
}
