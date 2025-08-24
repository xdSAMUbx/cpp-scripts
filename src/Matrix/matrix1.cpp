#include <iostream>
#include <vector>
#include "contigousMatrix.h"
#include "vecUtilities.h"

int main()
{
    int rows = 5, cols = 5;
    std::vector<int> shape = {4, 5};
    std::vector<std::vector<int>> mat(rows, std::vector<int>(cols, 0));
    std::vector<int> *ptr = mat.data();
    int cont = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mat[i][j] = cont++;
        }
    }
    printMS(mat, shape);
    std::cout << std::endl;
    std::vector<int> matC = Matrix(mat, shape);
    showVector(matC);

    return 0;
}
