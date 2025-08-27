#include <iostream>
#include <vector>

template <typename T>
struct Point
{
    T x, y;
};

std::vector<Point<double>> vecPoints(Point<double> &pi, Point<double> &pf, int &n)
{
    std::vector<Point<double>> res;
    double x, y;
    res.reserve(n);
    double stepx = (pf.x - pi.x) / (static_cast<double>(n - 1));
    double stepy = (pf.y - pi.y) / (static_cast<double>(n - 1));

    for (int i = 0; i < n; i++)
    {
        x = pi.x + stepx * static_cast<double>(i);
        y = pi.y + stepy * static_cast<double>(i);
        res.emplace_back(Point<double>{x, y});
    }
    return res;
}

int main()
{
    std::vector<Point<double>> vec;
    Point<double> p1{1.0, 1.0}, p2{0.0, 0.0};
    int n = 5;
    vec = vecPoints(p1, p2, n);
    for (int i = 0; i < n; i++)
        std::cout << "(" << vec[i].x << ", " << vec[i].y << ") ";
    std::cout << std::endl;
    return 0;
}