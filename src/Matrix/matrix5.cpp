#include <iostream>
#include <vector>
#include <cmath>
template <typename T>
class Point{
public:
    T x, y;

    static Point<T> point(const T& x,const T& y) {
        return Point<T>{x, y};
    }

    static std::vector<Point<T>> point(const std::vector<T>& x, const std::vector<T>& y) {
        std::vector<Point<T>> res;
        res.reserve(x.size());

        for (int i = 0; i < x.size(); i ++)
            res.emplace_back(Point<T>{x[i],y[i]});
        return res;
    }

    static double dist(const Point<T>& p1, const Point<T>& p2) {
        double dx = static_cast<double>(p2.x) - static_cast<double>(p1.x);
        double dy = static_cast<double>(p2.y) - static_cast<double>(p1.y);
        return std::sqrt(dx*dx + dy*dy);
    }
};

int main()
{
    std::vector<int> X = {0,1};
    std::vector<int> Y = {1,1};
    Point<double> pi = Point<double>::point(0.0,1.0);
    Point<double> pf = Point<double>::point(1.0,1.0);
    std::vector<Point<int>> p = Point<int>::point(X,Y);
    for (int i = 0; i < p.size(); i++)
        std::cout << p[i].x << " " << p[i].y << "\n";
    std::cout << std::endl;
    std::cout << Point<double>::dist(pi,pf) << std::endl;
    return 0;
}