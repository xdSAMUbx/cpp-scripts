#include <iostream>
#include <vector>
#include <array>

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

std::vector<int> eye(const int &n)
{
    std::vector<int> res;
    res.reserve(n * n);
    for (int i = 0; i < (n * n); i++)
        res.emplace_back((i % (n + 1) == 0) ? 1 : 0);
    return res;
}

std::vector<int> matrix(const std::vector<std::vector<int>> &mat)
{
    std::vector<int> res;
    res.reserve(mat.size() * mat[0].size());
    for (const auto &row : mat)
    {
        res.insert(res.end(), row.begin(), row.end());
    }
    return res;
}

void printMC(const std::vector<double> &mat, const std::vector<int> &shape)
{

    int rows = shape[0], cols = shape[1];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << mat[i * cols + j] << " ";
        }
        std::cout << "\n";
    }
}

void printM(const std::vector<std::vector<int>> &mat)
{
    for (const auto &row : mat)
    {
        for (const auto &col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }
}
