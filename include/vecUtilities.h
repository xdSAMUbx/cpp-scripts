#ifndef vecUtilities_h
#define vecUtilities_h

#include <vector>

void showVector(const std::vector<int> &vec);
std::vector<int> linspace(const int &ini, const int &fin, const int &step);
std::vector<int> randVector(const int &n, const int &x);

#endif