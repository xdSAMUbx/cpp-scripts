#pragma once
#include <vector>
#include <array>

void printM(const std::vector<std::vector<int>> &mat);
void printMC(const std::vector<double> &mat, const std::vector<int> &shape);
std::vector<int> matrix(const std::vector<std::vector<int>> &mat);
std::vector<int> eye(const int &n);
std::vector<int> T(std::vector<int> &mat, std::vector<int> &shape);
