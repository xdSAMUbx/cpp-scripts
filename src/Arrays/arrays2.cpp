#include <iostream>
#include <array>
#include <vector>
#include "vecUtilities.h"

int main()
{
    std::vector<int> v;
    int x = 0, y = 100, z = 10;
    v = ones(z);
    showVector(v);
    return 0;
}