// Demonstrate operator overloading using 2 dimensional points.
#include <iostream>
#include <cctype>

using namespace std;

// A struct is like a class, but everything is public by default.
// This is a 2d point, which doesn't need full OOP protection.
struct Point
{
    double x;
    double y;

    // Constructors
    Point();
    Point(double x, double y);

    // operators (member operators only specify rhs)
    Point operator+(Point &rhs);
    Point operator/(double rhs);
};


// insertion operator
ostream& operator<<(ostream &lhs, Point &rhs);

// extraction operator
istream& operator>>(istream &lhs, Point &rhs);

int main()
{
    Point p1, p2;
    Point p3;

    // read the points
    cout << "Enter p1: ";
    cin >> p1;
    cout << "Enter p2: ";
    cin >> p2;

    // print the result
    cout << "You entered " << p1 << " and " << p2 << endl;
    p3 = (p1+p2)/2.0;
    cout << "Midpoint: " << p3 << endl;
}


//////////////////////////////////////////
// Point Implementation
//////////////////////////////////////////
Point::Point() : Point(0.0, 0.0)
{
    // nothing to do here, this uses constructor dispatch
}


Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}


Point Point::operator+(Point &rhs)
{
    // effect
    return Point(x+rhs.x, y+rhs.y);
}


Point Point::operator/(double rhs)
{
    //effect
    return Point(x/rhs, y/rhs);
}


// insertion operator
ostream& operator<<(ostream &lhs, Point &rhs)
{
    // side effect
    lhs << "(" << rhs.x << ", " << rhs.y << ")";

    // effect
    return lhs;
}

// extraction operator
istream& operator>>(istream &lhs, Point &rhs)
{
    // side effect
    lhs >> rhs.x >> rhs.y;

    // effect
    return lhs;
}