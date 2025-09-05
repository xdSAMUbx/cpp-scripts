#include <iostream>
#include <vector>

template<typename T>
std::vector<T> randGen(const T& max, const int& n)
{
  std::vector<T> res;
  res.reserve(n);
  for (int i = 0; i < n; i++)
  {
    T num = static_cast<T>(rand()) / RAND_MAX * max;
    res.emplace_back(num);
  }

  return res;
}

template<typename T>
void printV(const std::vector<T>& vec)
{
  std::cout << "[ ";
  for (T val : vec)
    std::cout << val << " ";
  std::cout << "]\n";
}

int main()
{
  int n;
  double max;
  std::vector<double> vec;
  std::cout << "Ingrese la cantidad de datos que desea: ";
  std::cin >> n;
  std::cout << "Ingrese el valor máximo para generar los valores aleatorios: ";
  std::cin >> max;
  srand(time(nullptr));
  vec = randGen(static_cast<double>(max), n);
  printV(vec);

  return 0;
}
