#include <iostream>
#include <vector>

template<typename T>
void printV(const std::vector<T>& vec)
{
  std::cout << "[ ";
  for(T val : vec)
    std::cout << val << " ";
  std::cout << "]\n";
}

template<typename T>
std::vector<T> randVec(const T& max, const int& n)
{
  std::vector<T> res;
  res.reserve(n);
  for(int i = 0; i < n; i++)
  {
    T num = static_cast<T>(rand()) / RAND_MAX * max;
    res.emplace_back(num);
  }
  return res;
}

template<typename T>
T prom(const std::vector<T>& vec)
{
  T res;
  res = 0;
  for (T val : vec)
    res += val;
  res = res/vec.size();
  return res;
}

template<typename T>
std::vector<T> weight(const std::vector<T>& vec)
{
  T sum = 0;
  std::vector<T> res;
  for (T val : vec)
    sum += val;
  
  res.resize(vec.size());
  for (size_t i = 0; i < vec.size(); i++)
       res[i] = vec[i]/sum;
  return res;
}

template<typename T>
T promW(const std::vector<T>& vals, const std::vector<T>& pesos)
{
  T num = 0, den = 0;
  for(size_t i = 0; i < vals.size(); i++)
  {
    num += vals[i]*pesos[i];
    den += pesos[i];
  }
  return num/den;
}

int main()
{
  int n;
  double val = 100.0;
  std::vector<double> vec, w;

  std::cout << "Ingrese cuantos valores quiere: ";
  std::cin >> n;

  srand(time(nullptr));

  vec = randVec(val, n);
  printV(vec);
  
  std::cout << "La media es la siguiente: " << prom(vec) << "\n";

  w = weight(vec);
  std::cout << "El vector de pesos es: ";
  printV(w);

  std::cout << "El promedio ponderado es: " << promW(vec, w) << "\n";
  
  return 0;
}
