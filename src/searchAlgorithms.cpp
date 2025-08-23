#include <iostream>
#include <vector>

int linSearch(const std::vector<int> &vec, const int &num)
{
    int val, i, pos;
    for (int i = 0; i < vec.size(); i++)
    {
        if (*(vec.data() + i) == num)
        {
            return i;
        }
    }
    return -1;
}

int binSearch(const std::vector<int> &vec, const int &num)
{
    int right, left, mid;
    left = 0;
    right = vec.size() - 1;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (vec[mid] == num)
        {
            return mid;
        }
        else if (vec[mid] > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}