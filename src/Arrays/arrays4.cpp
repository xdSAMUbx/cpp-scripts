#include <iostream>
#include <vector>

struct Point2D
{
    double x, y;
};

std::vector<Point2D> pointArr(const int &n)
{
    std::vector<Point2D> vec;
    vec.reserve(n);
    for (int i = 0; i < n; i++)
    {
        vec.emplace_back(Point2D{static_cast<double>(i), static_cast<double>(i - 1)});
    }
    return vec;
}

int main()
{
    std::vector<Point2D> vec;
    vec = pointArr(3);
    for (auto val : vec)
        std::cout << "(" << val.x << ", " << val.y << ") ";
    std::cout << "\n";
    return 0;
}