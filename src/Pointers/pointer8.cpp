#include <iostream>

struct Point2D
{
    double x, y;
};

int main()
{
    int *pInt = new int(2);
    delete pInt;
    pInt = nullptr;

    Point2D *pP = new Point2D{1.0, 2.0};
    //(*pP).x = 2.0;
    //(*pP).y = 3.0;
    delete pP;
    pP = nullptr;

    int *pInt1 = new int();
    int **pInt2 = &pInt1;
    int val = **pInt2;
    delete pInt1;
    *pInt2 = nullptr;
    pInt2 = nullptr;
    return 0;
}