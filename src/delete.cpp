#include <iostream>

//#define DELETE

using namespace std;

struct Coordonnee
{
    double x;
    double y;
    Coordonnee() : x(0.), y(0.) {}
    Coordonnee(double x, double y) : x(x), y(y) {}
};

class Point 
{
   private:
      Coordonnee coordonnee;
      
   public:
      // Constructeurs
      Point() {}
      Point(double x, double y) : coordonnee(x, y) {}
      #ifdef DELETE
      Point(const Point& point) = delete; // constructeur de copie
      #endif
      
      // Destructeur  
      ~Point() = default;

      // Accesseurs et mutateurs
      double getX() const { return coordonnee.x; }
      void setX(double x) { this->coordonnee.x = x; }
      double getY() const { return coordonnee.y; }
      void setY(double y) { this->coordonnee.y = y; }

      // Surcharge
      #ifdef DELETE
      Point& operator=(const Point& point) = delete; // copie
      #endif
      friend ostream& operator<<(ostream& os, const Point& point);
};

ostream& operator<<(ostream& os, const Point& point)
{
   os << "<" << point.coordonnee.x << "," << point.coordonnee.y << ">";
   return os;
}

int main()
{
    Point p0, p1(4, 0.0), p2(2.5, 2.5);
    cout << "P0 = " << p0 << endl;
    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;

    Point p3(p2);
    cout << "P3 = " << p3 << endl;

    p0 = p3;
    cout << "P0 = " << p0 << endl;

    return 0;
}
