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

int main()
{
  int n; double max;
  std::cout << "Ingrese la cantidad de puntos que desea tener en la grilla: ";
  std::cin >> n;
  std::cout << "Ingrese el máximo valor al que llega la grilla: ";
  std::cin >> max;

  std::array<int,2> shape = findMat(n);
  std::cout << shape[0] << ", " << shape[1] << "\n";

  return 0;
}
