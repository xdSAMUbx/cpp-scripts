#include <iostream>
#include <vector>

void showVector(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> linspace(const int &ini, const int &fin, const int &step)
{
    int n = (fin - ini) / step;
    std::vector<int> arr; // Crea la variable arr de tipo vector entero
    arr.reserve(n);       // Reserva memoria para los n que se obtengan
    for (int i = 0; i <= n; i++)
    {
        arr.push_back(ini + step * i); // Ingresa el nuevo valor en la lista
    }
    return arr;
}

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
