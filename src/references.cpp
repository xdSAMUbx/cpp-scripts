#include <iostream>

void incremento(int &n) // Obtiene la referencia del valor
{                       // que se deseea ajustar
    n++;
}

int main()
{
    int a = 5;
    incremento(a); // Se esta enviando la dirección de memoria de a

    return 0;
}