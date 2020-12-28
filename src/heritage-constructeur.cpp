#include <iostream>

using namespace std;

class Point
{
    public:
        Point(double x, double y) : x(x), y(y) {}
        Point() : x(0.), y(0.) {}
        friend ostream & operator << (ostream & os, const Point & p);

    private:
        double x;
        double y;
};

ostream & operator << (ostream & os, const Point & p) 
{
   os << "<" << p.x << "," << p.y << ">";
   return os;
}

class PointCouleur : public Point
{
    public:
        using Point::Point;
        //...
 
    private:
        unsigned int couleur;
};

int main()
{
    PointCouleur p1;
    PointCouleur p2(2, 2);

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}
