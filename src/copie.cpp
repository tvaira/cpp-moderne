#include <iostream>

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
      Point(const Point& point) = default; // constructeur de copie
      
      // Destructeur  
      ~Point() = default;

      // Accesseurs et mutateurs
      double getX() const { return coordonnee.x; }
      void setX(double x) { this->coordonnee.x = x; }
      double getY() const { return coordonnee.y; }
      void setY(double y) { this->coordonnee.y = y; }

      // Surcharge
      Point& operator=(const Point& point) = default; // copie
      friend ostream& operator<<(ostream& os, const Point& point);
};

ostream& operator<<(ostream& os, const Point& point)
{
   os << "<" << point.coordonnee.x << "," << point.coordonnee.y << ">";
   return os;
}

int main()
{
    cout << "Les points :" << endl;
    Point p0, p1(4, 0.0), p2(2.5, 2.5);
    cout << "p0 = " << p0 << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    cout << "Constructeur de copie : Point p3(p2)" << endl;
    Point p3(p2);
    cout << "p3 = " << p3 << endl;

    cout << "Opérateur de copie : p0 = p3" << endl;
    p0 = p3;
    cout << "p0 = " << p0 << endl;

    return 0;
}
