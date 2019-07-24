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

    Point(float x, float y) : x(x), y(y) {}
public:
    float x, y;

    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return {r*cos(theta), r*sin(theta)};
    }

    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};


int main ()
{
    auto p1 = Point::NewCartesian(4, 5);
    auto p2 = Point::NewPolar(4, M_PI_4);

    cout << p1 << endl;
    cout << p2 << endl;
    return 0;
}
