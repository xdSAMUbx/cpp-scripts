#include <iostream>

int divi(const int &x1, const int &x2)
{
    if (x2 == 0)
    {
        std::cerr << "División por 0" << std::endl;
        return 0;
    }
    return x1 / x2;
}

int mult(const int &x1, const int &x2)
{
    return x1 * x2;
}

int rest(const int &x1, const int &x2)
{
    return x1 - x2;
}

int sum(const int &x1, const int &x2)
{
    return x1 + x2;
}

void lineas(const std::string &c, const int &n)
{
    for (int i = 1; i <= n; i++)
        std::cout << c;
}

int main()
{
    int x, y;
    lineas("-", 30);
    std::cout << "\nIngrese el valor x: ";
    std::cin >> x;
    lineas("-", 30);
    std::cout << "\nIngrese el valor de y: ";
    std::cin >> y;
    lineas("-", 30);
    std::cout << "\nLa suma es: " << sum(x, y) << "\n";
    std::cout << "\nLa resta es: " << rest(x, y) << "\n";
    std::cout << "\nLa multiplicación es: " << mult(x, y) << "\n";
    std::cout << "\nLa división es: " << divi(x, y) << "\n";
    lineas("-", 30);
    std::cout << "\n";
    return 0;
}