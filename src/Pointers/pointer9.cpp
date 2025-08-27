#include <iostream>

int main()
{
    int n = 5;
    int *pArr = new int[n](); // Todos quedan inicializados en 0
    for (int i = 0; i < n; i++)
    {
        pArr[i] = i;
        std::cout << pArr[i] << " ";
    }
    std::cout << std::endl;
    delete[] pArr;
    pArr = nullptr;
    return 0;
}