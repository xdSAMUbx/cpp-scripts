#include <iostream>

int main()
{
    // Esto es un puntero vacio, no hace nada
    void *ptr = nullptr;

    // Aquí creamos una variable y le asignamos un puntero a esa variable:
    int var = 8;      // var se le asigna en memoria el valor de 8
    int *ptr1 = &var; // Luego el puntero de tipo entero ptr1 obtiene la dirección de var
    *ptr1 = 10;       // Finalmente se desreferencia (obtiene el valor o cambia el valor)
                      // de var, por eso permite cambiar a 10 le estoy asignando un nuevo numero

    int **ptr2 = &ptr1;
    return 0;
}