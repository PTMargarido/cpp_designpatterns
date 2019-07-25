#include <memory>
#include <iostream>
#include <string>
using namespace std;

struct Point
{
    int x{ 0 }, y{ 0 };

    Point(){}

    Point(const int x, const int y) : x{x}, y{y} {}

    friend ostream &operator<<(ostream &os, const Point &point)
    {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

struct Line
{
    Point *start, *end;

    Line(Point* const start, Point* const end)
        : start(start), end(end)
    {
    }

    ~Line()
    {
        cout << *this << endl;
        delete start;
        delete end;
    }

    friend ostream &operator<<(ostream &os, const Line &line)
    {
        os << "start: " << *line.start << " end: " << *line.end;
        return os;
    }

    Line deep_copy() const
    {
       Point* start_copy = new Point(*start); 
       Point* end_copy = new Point(*end); 
       return {start_copy, end_copy};
    }
};

int main ()
{
    Line test{new Point{0,0}, new Point{1,2}};
    Line test_copy = test.deep_copy();
    cout << test << endl;
    cout << test_copy << endl;
    test_copy.start->x = -5;
    cout << test_copy << endl;
    cout << test << endl;

    return 0;
}
