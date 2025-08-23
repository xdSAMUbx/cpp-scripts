#include <iostream>
#include <vector>
#include "searchAlgorithms.h"

void showVec(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> linspace(const int &init, const int &fin, const int &step)
{
    int n = (fin - init) / step;
    std::vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i <= n; i++)
    {
        arr.push_back(init + step * i);
    }
    return arr;
}

int main()
{
    int x = 294;
    std::vector<int> vec = linspace(0, 10000, 4);
    int pos = binSearch(vec, x);
    std::cout << "El número " << x << " esta en la posición: " << pos << "\n";
    return 0;
}