#pragma once
#include <vector>
#include <array>

void printM(const std::vector<std::vector<int>> &mat);
void printMC(const std::vector<int> &mat, const std::array<int, 2> &shape);
std::vector<int> matrix(const std::vector<std::vector<int>> &mat);
std::vector<int> eye(const int &n);
