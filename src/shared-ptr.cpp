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

    std::cout << "p1 : " << (p1 ? "not null" : "null") << endl;
    std::cout << "compteur p1 : " << p1.use_count() << endl;
    cout << p1->getX() << "," << p1->getY() << endl;
    
    shared_ptr<Point> p2(move(p1));

    std::cout << "p1 : " << (p1 ? "not null" : "null") << endl;
    std::cout << "compteur p1 : " << p1.use_count() << endl;
    std::cout << "p2 : " << (p2 ? "not null" : "null") << endl;
    std::cout << "compteur p2 : " << p2.use_count() << endl;
    cout << p2->getX() << "," << p2->getY() << endl;
    
    shared_ptr<Point> p3; 
    std::cout << "p3 : " << (p3 ? "not null" : "null") << endl;
    std::cout << "compteur p3 : " << p3.use_count() << endl;

    p3 = p2;
    std::cout << "p2 : " << (p2 ? "not null" : "null") << endl;
    std::cout << "compteur p2 : " << p2.use_count() << endl;
    std::cout << "p3 : " << (p3 ? "not null" : "null") << endl;
    std::cout << "compteur p3 : " << p3.use_count() << endl;
    cout << p2->getX() << "," << p2->getY() << endl;
    cout << p3->getX() << "," << p3->getY() << endl;

    return 0; 
} 
