#include <iostream>
#include <vector>
#include <array>
#include "vecUtilities.h"
#include "contigousMatrix.h"

int main()
{
    std::vector<std::vector<int>> vec(2, std::vector<int>(2, 0));
    std::vector<int> shape = {4, 4};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            vec[i][i] = 1;
        }
    }

    printM(vec);
    std::vector<int> vec1 = eye(4);
    printV(vec1);
    printMC(vec1, shape);
    return 0;
}
