#include <iostream>
#include <vector>
#include <array>
#include <cmath>

template<typename T>
struct Point{
  T x, y;
};

std::array<int,2> findMat(const int& n)
{
  if (n <= 0)
    throw std::invalid_argument("Para generar la grilla debe ingresar un valor mayor a 0");
  int res = sqrt(n);
  if (res >= n)
    return {res, res};

  int res2 = n/res;
  if (res * res2 < n)
    return {res, res2+1};
  return {res, res2};
}

template<typename T>
std::vector<Point<T>> grid(const T& min, const T& max, const int& n)
{
  std::vector<Point<T>> res;
  std::array<int,2> shape;
  shape = findMat(n);
  int row = shape.at(0);
  int col = shape.at(1);
  res.resize(row*col);
  T stpX = (max - min) / static_cast<T>(row - 1);
  T stpY = (max - min) / static_cast<T>(col - 1);
  for (int i = 0; i < row; i++)
  {
    T x = min + static_cast<T>(i) * stpX;
    for (int j = 0; j < col; j++)
    {
      T y = min + static_cast<T>(j) * stpY;
      res[i * col + j] = Point<T>{x, y};
    }
  } 
  return res;
}

int main()
{
  int n; double max;
  std::cout << "Ingrese la cantidad de puntos que desea tener en la grilla: ";
  std::cin >> n;
  std::cout << "Ingrese el máximo valor al que llega la grilla: ";
  std::cin >> max;

  std::array<int,2> shape = findMat(n);
  std::cout << shape[0] << ", " << shape[1] << "\n";
  
  std::vector<Point<double>> grid1 = grid(1.0,max,n);
  for (int i = 0; i < n; i++)
    std::cout << "(" << grid1[i].x << ", " << grid1[i].y << ")\n";

  return 0;
}
