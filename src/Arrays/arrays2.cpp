#include <iostream>
#include <array>
#include <vector>
#include "vecUtilities.h"

int main()
{
    std::vector<int> v;
    int x = 0, y = 100, z = 11;
    v = ones(z);
    for (auto val : v)
        std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}