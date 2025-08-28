#include <vector>
#include <iostream>
#include <optional>
#include <cmath>
#include <fstream>
#include "contigousMatrix.h"
#include "vecUtilities.h"

template <typename T>
struct Point
{
    T x, y;
};

template <typename T>
std::vector<Point<T>> grid(const std::vector<T> &limits, const double &points)
{
    T xi = limits[0];
    T yi = limits[1];
    T xf = limits[2];
    T yf = limits[3];

    int n, m;

    n = m = floor(sqrt(points));
    std::vector<Point<T>> res;
    res.resize(n * m);

    T step_x = (xf - xi) / static_cast<T>(n - 1);
    T step_y = (yf - yi) / static_cast<T>(m - 1);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            res[(n - 1 - i) * m + (m - 1 - j)].x = xi + j * step_x;
            res[(n - 1 - i) * m + (m - 1 - j)].y = yi + i * step_y;
        }
    }
    return res;
}

int main()
{
    std::vector<Point<int>> vec;
    std::vector<int> limits = {0, 0, 10000, 10000};
    std::vector<int> shape{10000, 10000};
    vec = grid(limits, 1000000000);
    // Abrir archivo de salida
    std::ofstream file("grid.txt");
    if (!file.is_open())
    {
        std::cerr << "Error al abrir el archivo\n";
        return 1;
    }

    // Escribir cada punto en el archivo
    for (const Point<int> &val : vec)
        file << val.x << " " << val.y << "\n";

    file.close(); // cerrar el archivo
    return 0;
}