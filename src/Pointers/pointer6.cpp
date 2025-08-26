#include <iostream>

// Memoria dinámica con clases
class Student
{
public:
    std::string name;
    void print()
    {
        std::cout << name << std::endl;
    }
};

int main()
{
    int x = 4;               // Esta en el stack
    int *pInt = new int;     // Esta en el stack, guarda memoria para un entero en el heap
                             // Lo que devuelve es la dirección en memoria separada
                             // para un entero
    *pInt = 5;               // Guarda el valor en  el sitio reservado en el heap
    int *pInt1 = new int(2); // Es la manera de asignar el valor inmediato en la dirección
                             // de memoria reservada para un entero
    std::cout << "Valor en memoria " << pInt << std::endl;
    std::cout << "Desreferenciando el puntero: " << *pInt << std::endl;

    delete pInt; // Libera la memoria utilizada para poderla usar en algo más

    // Guardando espacio para arrays
    double *array = new double[4]; // Se genera el espacio en memoria
    array[0] = 1.0;                // Es importante ver la memoria dinamica como un bloque
    array[1] = 2.0;                // de código para evitar las fugas de memoria
    array[2] = 3.0;
    array[3] = 4.0;
    for (int i = 0; i < 4; i++)
        std::cout << "Valor en posición " << i << ": " << array[i] << "\n";
    delete[] array; // Se libera el espacio en memoria

    // Aplicando a una clase
    Student *student = new Student;
    (*student).name = "John";
    (*student).print();
    // Utilizando el operador ->
    student->name = "Mary"; // -> Es otra forma de acceder a los valores en heap
    student->print();
    delete student;
    // malloc() calloc() free()
    // Esta es una manera de manejar la mala localización de memoria
    try
    {
        double *bigArray = new double[999999999999999];
    }
    catch (std::bad_alloc &exp)
    {
        std::cout << "Mala memoria captada: " << exp.what() << "\n";
    }
    // Otra manera de verificar la utilización de la memoria:
    double *big_again = new (std::nothrow) double[999999999999999];
    if (big_again == NULL)
        std::cout << "Nuevamente fallaste al usar memoria!!\n";
    // Otra forma de asignar valores mediante punteros
    double *mydouble = new double(12.2);
    double *specific = new (mydouble) double(20.5);
    std::cout << *mydouble << "\n";
    delete mydouble, specific;
    return 0;
}