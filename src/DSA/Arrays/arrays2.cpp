#include <iostream>
#include <vector>

template<typename T>
void printV(const std::vector<T>& vec)
{
  std::cout << "[ ";
  for (auto val : vec)
    std::cout << val << " ";
  std::cout << "]\n";
}

template <typename T>
std::vector<T> vecGen(const int& n)
{
  std::vector<T> res;
  res.reserve(n);
  for (int i = 0; i < n; i ++)
       res.emplace_back(static_cast<T>(i));
  return res; 
}

int main()
{
  int n;
  std::vector<double> vec;
  std::cout << "Ingrese los valores a generar: ";
  std::cin >> n;
  vec = vecGen<double>(n);
  printV(vec);

  return 0;
}
