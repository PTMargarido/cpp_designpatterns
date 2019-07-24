#include <iostream>
#include <cmath>

using namespace std;
enum class PointType
{
    cartesian,
    polar
};

class Point
{

public:
    Point(float x, float y) : x(x), y(y) {}
    float x, y;

    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct PointFactory
{
    Point NewCartesian(float x, float y)
    {
        return {x, y};
    }

    Point NewPolar(float r, float theta)
    {
        return {r*cos(theta), r*sin(theta)};
    }
};

int main ()
{
    auto p1 = PointFactory().NewCartesian(4, 5);
    auto p2 = PointFactory().NewPolar(4, M_PI_4);

    cout << p1 << endl;
    cout << p2 << endl;
    return 0;
}
