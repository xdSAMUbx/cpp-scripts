#include <iostream>
#include <vector>
#include "contigousMatrix.h"

int main()
{
    std::vector<int> vec = {6, 2};
    std::vector<int> mat = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
    printM(mat, vec);
    std::cout << std::endl;
    return 0;
}