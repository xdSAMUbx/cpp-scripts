#include <iostream>
#include <vector>

struct Point2D
{
    int x, y;
};

int main()
{
    Point2D p1{1, 2};
    std::cout << "El punto es: (" << p1.x << ", " << p1.y << ")" << "\n";
    return 0;
}