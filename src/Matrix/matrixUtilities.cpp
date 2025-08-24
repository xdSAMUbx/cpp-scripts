#include <iostream>
#include <vector>

std::vector<int> Matrix(const std::vector<std::vector<int>> &mat, const std::vector<int> &shape)
{
    std::vector<int> matC;
    const int *pSh = shape.data();
    matC.reserve(pSh[0] * pSh[1]);
    for (int i = 0; i < pSh[0]; i++)
    {
        for (int j = 0; j < pSh[1]; j++)
        {
            matC.push_back(mat[i][j]);
        }
    }

    return matC;
}

void printMS(const std::vector<std::vector<int>> &mat, const std::vector<int> &shape)
{
    for (auto &row : mat)
    {
        std::cout << "[ ";
        for (auto val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
    }
}

void printMC(std::vector<int> &vec, std::vector<int> &shape)
{
    int *ind = shape.data();
    int *mat = vec.data();
    for (int i = 0; i < vec.size() / ind[1]; i++)
    {
        for (int j = 0; j < vec.size() / ind[0]; j++)
        {
            std::cout << mat[i * ind[1] + j] << " ";
        }
        std::cout << std::endl;
    }
}
