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

std::vector<Point<double>> grid(const std::vector<double> &limits,
                                const size_t &n) {
  if (n <= 0)
    throw std::invalid_argument("n no puede ser menor o igual a 0.");

  std::vector<Point<double>> res;
  std::array<size_t, 2> shape = findMat(n);

  double stpX = (limits[2] - limits[0]) / static_cast<double>(shape[0] - 1);
  double stpY = (limits[3] - limits[1]) / static_cast<double>(shape[1] - 1);

  res.resize(shape[0] * shape[1]);
  for (int i = 0; i < shape[0]; i++) {
    res[shape[0] * i + j] = limits[0] + static_cast<double>(i) * stepX;
    for (int j = 0; i < shape[1]; j++) {
    }
  }

  return res;
}

int main() {
  Point p1(1, 2);
  p1.shwPoint();
  return 0;
}
