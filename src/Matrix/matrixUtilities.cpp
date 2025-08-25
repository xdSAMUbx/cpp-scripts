#include <iostream>
#include <vector>
#include <array>

std::vector<int> eye(const int &n)
{
    std::vector<int> res;
    res.reserve(n * n + 1);
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

void printMC(const std::vector<int> &mat, const std::array<int, 2> &shape)
{

    for (int i = 0; i < mat.size() / shape[1]; i++)
    {
        for (int j = 0; j < mat.size() / shape[0]; j++)
        {
            std::cout << mat[i * shape[1] + j] << " ";
        }
        std::cout << std::endl;
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
