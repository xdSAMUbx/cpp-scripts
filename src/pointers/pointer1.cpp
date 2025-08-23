#include <iostream>

int main()
{
    int x, y;
    int *px = &x; // Siempre deben apuntar a la dirección en memoria
    int *py = &y;
    std::cout << "Ingrese el valor que desea sumar : ";
    std::cin >> x;
    std::cout << "La referencia a " << x << " es: " << &x << "\n";
    std::cout << "Ingrese el segundo valor que desea sumar: ";
    std::cin >> y;
    std::cout << "La referencia a " << y << " es: " << &y << "\n";
    std::cout << "La suma de ambos es: " << *px + *py << "\n";
    return 0;
}