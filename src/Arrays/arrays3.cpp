#include <iostream>
#include <vector>
#include <array>
#include "vecUtilities.h"
#include "contigousMatrix.h"

std::vector<int> matrix(const std::vector<std::vector<int>> &mat)
{
    std::vector<int> matC;
    matC.reserve(mat.size() * mat[0].size());
    for (const auto &row : mat)
    {
        matC.insert(matC.end(), row.begin(), row.end());
    }
    return matC;
}

int main()
{
    std::vector<std::vector<int>> vec(2, std::vector<int>(2, 0));
    std::vector<int> shape = {2, 2};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            vec[i][i] = 1;
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> vec1 = matrix(vec);
    showVector(vec1);
    printMC(vec1, shape);
    return 0;
}
