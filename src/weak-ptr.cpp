#include <iostream> 
#include <memory>

using namespace std; 

class Point
{
    private:
        double x; 
        double y; 
  
    public:
        Point() : Point(0., 0.) { } 
        Point(double x, double y) : x(x), y(y) { cout << __FUNCTION__ << endl; }
        Point(const Point & p) : x(p.x), y(p.y) { cout << __FUNCTION__ << endl; } 
        ~Point() { cout << __FUNCTION__ << endl; }
        double getX() const { return x; }
        double getY() const { return y; }
}; 
  
int main() 
{   
    shared_ptr<Point> p1(new Point(10, 5));

    weak_ptr<Point> wp1;
    weak_ptr<Point> wp2(wp1);
    weak_ptr<Point> wp3(p1);

    cout << "use_count wp1 : " << wp1.use_count() << '\n';
    cout << "use_count wp2 : " << wp2.use_count() << '\n';
    cout << "use_count wp3 : " << wp3.use_count() << '\n';

    return 0; 
} 
