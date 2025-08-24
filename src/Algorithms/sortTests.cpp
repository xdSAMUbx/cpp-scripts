#include <iostream>
#include "sortAlgorithms.h"
#include "vecUtilities.h"

int main()
{
    std::vector<int> arr;
    arr = randVector(25, 100);
    showVector(arr);
    arr = bubbleSort(arr);
    showVector(arr);
    return 0;
}
