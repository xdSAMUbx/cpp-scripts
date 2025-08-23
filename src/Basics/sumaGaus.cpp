#include <iostream>

int suma(const int &n)
{
    int i, sum = 0;

    for (i = 1; i <= n; i++)
    {
        sum = (i * (i + 1)) / 2;
    }
    return sum;
}

int main()
{
    int x;

    x = 100;
    std::cout << "La suma hasta el número " << x << " es: " << suma(x) << std::endl;

    return 0;
}