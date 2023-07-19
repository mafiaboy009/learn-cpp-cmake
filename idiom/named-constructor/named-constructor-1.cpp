#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    float x{}, y{};
    Point(float a = 0, float b = 0) : x{a}, y{b} {}

protected:
public:
    static Point RectangularPoint(float x, float y)
    {
        return Point(x, y);
    }
    static Point PolarPoint(float radius, float angle)
    {
        return Point(radius * cos(angle), radius * sin(angle));
    }

    float getX() { return x; }
    float getY() { return y; }
};

int main()
{

    Point recPoint = Point::RectangularPoint(4.5, 8.5);
    Point polarPoint = Point::PolarPoint(4.5, 8.5);

    cout << "Rectangular point: (" << recPoint.getX() << ", " << recPoint.getY() << ")" << endl;
    cout << "Polar point: (" << polarPoint.getX() << ", " << polarPoint.getY() << ")" << endl;

    return EXIT_SUCCESS;
}

/*
Note: Make sure your constructors are in the protected section if you expect Fred to have derived classes.
*/