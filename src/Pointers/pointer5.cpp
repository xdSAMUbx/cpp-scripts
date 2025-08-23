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

int loc(const std::vector<int> &vec, const int &pos)
{
    if (pos < 0 || pos >= static_cast<int>(vec.size()))
    {
        throw std::out_of_range("Posición fuera del rango del vector");
    }
    return *(vec.data() + pos); // Es muy distinto hacer *ptr + pos ya que hace una operación de suma normal
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

int main()
{
    int x = 0, y = 10, z = 1, pos = 4;
    std::vector<int> arr = linspace(x, y, z);
    int *ptr = arr.data(); // Esta es la forma moderna de poder apuntar a una lista
    showVector(arr);
    int val = loc(arr, pos);
    std::cout << "La posición " << pos << " es: " << val << "\n";
    return 0;
}