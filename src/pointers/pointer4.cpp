#include <iostream>

int main()
{
    int x, *ptr = &x;
    std::cout << "Ingrese el valor inicial: ";
    std::cin >> x;

    std::cout << "El valor es: " << *ptr << "\n";

    std::cout << "Ingrese el valor por el cual desea cambiar: ";
    std::cin >> *ptr;

    std::cout << "El nuevo valor es: " << *ptr << std::endl;
    return 0;
}