#include <iostream>
#include <vector>

void printV(const std::vector<double> &vec)
{
    std::cout << "[ ";
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> ones(const int &n)
{
    std::vector<int> res;
    if (n <= 0)
        return res;
    for (int i = 0; i <= n; i++)
        res.emplace_back(1);
    return res;
}

std::vector<int> zeros(const int &n)
{
    std::vector<int> res;
    if (n <= 0)
        return res;
    for (int i = 0; i <= n; i++)
        res.emplace_back(0);
    return res;
}

std::vector<int> linspace(const int &ini, const int &fin, const int &n)
{
    std::vector<int> res;
    if (n <= 0)
        return res;
    int step = (fin - ini) / (n - 1);
    res.reserve(n);
    for (int i = 0; i < n; i++)
        res.emplace_back(ini + step * i);
    return res;
}

std::vector<int> arange(const int &ini, const int &fin, const int &step)
{
    std::vector<int> res;
    res.reserve((fin - ini) / step);
    for (int i = ini; i <= fin; i += step)
        res.emplace_back(i);
    return res;
}
