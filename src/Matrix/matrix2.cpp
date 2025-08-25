#include <iostream>
#include <vector>
#include <array>
#include "contigousMatrix.h"
#include "vecUtilities.h"

std::vector<int> T(std::vector<int> &mat, std::vector<int> &shape)
{
    int rows = shape[0], cols = shape[1];
    std::vector<int> res;
    res.reserve(rows * cols);
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            res.emplace_back(mat[i * cols + j]);
        }
    }
    return res;
}

int main()
{
    int rows = 1, cols = 5, cont;
    std::vector<std::vector<int>> mat(rows, std::vector<int>(cols, 0));
    std::vector<int> shape = {rows, cols};
    std::vector<int> tshape = {cols, rows};
    cont = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat[i][j] = cont++;
        }
    }
    printM(mat);
    std::vector<int> mat2 = matrix(mat);
    // i * columnas + j
    std::vector<int> tmat2 = T(mat2, shape);
    printMC(tmat2, tshape);

    return 0;
}