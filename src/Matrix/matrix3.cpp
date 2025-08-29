#include <iostream>
#include <vector>
#include "matrix.h"

std::vector<double> matrix2(const int &n)
{
    std::vector<double> mat;
    mat.resize(n * n);
    double cont = 0.0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i * n + j] = 0.5;
        }
    }
    return mat;
}

std::vector<double> matrix1(const int &n)
{
    std::vector<double> mat;
    mat.reserve(n * n);
    double cont = 1;
    for (int i = 0; i < n * n; i++)
    {
        mat.emplace_back(cont);
        cont++;
    }
    return mat;
}

int main()
{
    int n = 3;
    std::vector<double> mat;
    std::vector<int> shape = {n, n};
    mat = matrix2(n);
    printMC(mat, shape);
    return 0;
}