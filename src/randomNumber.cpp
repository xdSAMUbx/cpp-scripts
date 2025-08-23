#include <iostream>
#include <vector>

std::vector<int> randVector(const int &n, const int &x)
{
    std::vector<int> arr;
    arr.reserve(n);
    srand(time(nullptr)); // Como se usa nullptr la semilla cambia con la hora
    for (int i = 0; i <= n; i++)
    {
        arr.push_back((rand() % x) + 1); // Como números pseudoaleatorios de 1 a x
    }
    return arr;
}

int main()
{
    std::vector<int> vec;
    vec = randVector(100, 1000);
    int *ptr = vec.data();

    std::cout << *ptr << std::endl;

    return 0;
}