#include <iostream>
#include <vector>

void printM(std::vector<int> &vec, std::vector<int> &shape)
{
    int *ind = shape.data();
    int *mat = vec.data();
    for (int i = 0; i < vec.size() / ind[1]; i++)
    {
        for (int j = 0; j < vec.size() / ind[0]; j++)
        {
            std::cout << mat[i * ind[1] + j] << " ";
        }
        std::cout << std::endl;
    }
}
