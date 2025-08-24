#include <iostream>
#include <array>
#include <vector>

int main()
{
    // Se construye un array con espacio de 5
    const int n = 5;
    std::array<int, n> arr;
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Se construye un vector con un espacio de 5
    int n1 = 5;
    std::vector<int> arr1;
    arr1.reserve(n1);
    for (int i = 0; i < n1; i++)
    {
        arr1.emplace_back(i);
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
