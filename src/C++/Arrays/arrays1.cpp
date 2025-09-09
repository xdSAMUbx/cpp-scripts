#include <iostream>
#include <vector>

int main()
{
  std::vector<float> vec1;

  for (int i = 0; i < 10 ; i++)
  {
       vec1.emplace_back(i);
       std::cout << vec1[i] << " " ;
  }
  std::cout << std::endl;

  return 0;
}
