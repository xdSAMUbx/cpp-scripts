#include <iostream>
#include <vector>

template<typename T>
std::vector<T> vecGen(const int& n)
{
    std::vector<T> res;
    res.reserve(n);
    for (int i = 0; i < n; i++)
        res.emplace_back(static_cast<T>(i));
    return res;
}

int main()
{
    int n;
    
    std::cout << "Ingrese la cantida de valores que desea ingresar: ";
    std::cin >> n;
    std::vector<double> res = vecGen<double>(n);
    for (double val : res)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}
