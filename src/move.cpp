#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

//#define COUT
#define MOVE
#define DURATION

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
      Coordonnee *coordonnee;
      
   public:
      // Constructeurs
      Point() : coordonnee(new Coordonnee()) {
          ++constructions;
          #ifdef COUT
          cout << "default " << __FUNCTION__ << " " << this << endl;
          #endif
      }
      Point(double x, double y) : coordonnee(new Coordonnee(x, y)) {
          ++constructions;
          #ifdef COUT
          cout << __FUNCTION__ << " " << this << endl;
          #endif
      }
      Point(const Point& point); // copie
      #ifdef MOVE
      Point(Point&& point) noexcept; // déplacement
      #endif
      
      // Destructeur  
      ~Point() { if(coordonnee) delete coordonnee; };

      // Accesseurs et mutateurs
      double getX() const { return coordonnee->x; }
      void setX(double x) { this->coordonnee->x = x; }
      double getY() const { return coordonnee->y; }
      void setY(double y) { this->coordonnee->y = y; }

      // Surcharge
      Point& operator=(const Point& point); // copie
      #ifdef MOVE
      Point& operator=(Point&& point); // déplacement
      #endif
      friend ostream& operator<<(ostream& os, const Point& point);
      friend Point operator+(const Point& p1, const Point& p2);

      // Services
      static void swap_v1(Point& a, Point& b);
      #ifdef MOVE
      static void swap_v2(Point& a, Point& b);
      #endif

      // Comptage
      static int constructions;
      static int copies;
      static int deplacements;
      static void reset();
};

int Point::constructions = 0;
int Point::copies = 0;
int Point::deplacements = 0;

// Constructeur de copie
Point::Point(const Point& point) : coordonnee(new Coordonnee(point.coordonnee->x, point.coordonnee->y))
{
    ++constructions;
    #ifdef COUT
    cout << "copy " << __FUNCTION__ << " " << this << endl;
    #endif
}

#ifdef MOVE
// Constructeur de déplacement
Point::Point(Point&& point) noexcept : coordonnee(point.coordonnee)
{
    point.coordonnee = nullptr;
    ++deplacements;
    #ifdef COUT
    cout << "move " << __FUNCTION__ << " " << this << endl;
    #endif
}
#endif

// Copie
Point& Point::operator=(const Point& point)
{
    if(this != &point)
    {
        delete coordonnee;
        coordonnee = new Coordonnee(point.coordonnee->x, point.coordonnee->y);
        ++copies;
        #ifdef COUT
        cout << "copy " << __FUNCTION__ << " " << this << endl;
        #endif
    }

    return *this;
}

#ifdef MOVE
// Déplacement
Point& Point::operator=(Point&& point)
{
    if(this != &point)
    {
        delete coordonnee;
        coordonnee = point.coordonnee;
        point.coordonnee = nullptr;
        ++deplacements;
        #ifdef COUT
        cout << "move " << __FUNCTION__ << " " << this << endl;
        #endif
    }

    return *this;
}
#endif

// Surcharge
ostream& operator<<(ostream& os, const Point& point)
{
   os << "<" << point.coordonnee->x << "," << point.coordonnee->y << ">";
   return os;
}

Point operator+(const Point& p1, const Point& p2) 
{
   Point p;

   p.coordonnee->x = p1.coordonnee->x + p2.coordonnee->x;
   p.coordonnee->y = p1.coordonnee->y + p2.coordonnee->y;
   
   return p;
}

void Point::swap_v1(Point& a, Point& b)
{
    Point tmp(a);   // constructeur de copie
    a = b;          // opérateur de copie
    b = tmp;        // opérateur de copie
}

#ifdef MOVE
void Point::swap_v2(Point& a, Point& b)
{    
    Point tmp(move(a));
    a = move(b);
    b = move(tmp);
}
#endif

void Point::reset()
{
    constructions = 0;
    copies = 0;
    deplacements = 0;
}

int main()
{
    /*
    #ifdef MOVE
    Point p1(2.5, 2.5);
    cout << "P1 = " << p1 << endl;

    Point&& rp1 = move(p1);
    cout << "P1 = " << p1 << endl;
    cout << "rp1 = " << rp1 << endl;
    #endif
    */

    #ifndef DURATION
        cout << "points :" << endl;
        Point p2, p3(1.,1.), p4(2.5, 2.5);
        cout << "p2 = " << p2 << endl;
        cout << "p3 = " << p3 << endl;
        cout << "p4 = " << p4 << endl;
        cout << endl;

        cout << "p2 = p3 + p4" << endl;
        p2 = p3 + p4; // move
        cout << "p2 = " << p2 << endl;
        cout << endl;

        #ifdef MOVE
        cout << "p5 <- p2" << endl;
        Point p5(move(p2)); // move        
        cout << "p5 = " << p5 << endl;
        cout << endl;
        #endif

        cout << "p3 <-> p4" << endl;
        Point::swap_v1(p3, p4);        
        cout << "p3 = " << p3 << endl;
        cout << "p4 = " << p4 << endl;
        cout << endl;

        #ifdef MOVE
        cout << "p3 <-> p4" << endl;
        Point::swap_v2(p3, p4); // move        
        cout << "p3 = " << p3 << endl;
        cout << "p4 = " << p4 << endl;
        cout << endl;
        #endif
    #else
        Point::reset();
        auto start = std::chrono::high_resolution_clock::now();
        
        vector<Point> points;
        for (int i = 0; i < 1000000; ++i)
        {
            points.push_back(Point(i, i*2));
        }

        #ifdef MOVE
        vector<Point> courbe(move(points));
        #else
        vector<Point> courbe(points);
        #endif

        reverse(courbe.begin(), courbe.end());

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Duration : " << elapsed.count() << " s\n";
        cout << "Constructions : " << Point::constructions << "\n";
        cout << "Copies : " << Point::copies << "\n";
        cout << "Deplacements : " << Point::deplacements << "\n";
        cout << "Total : " << (Point::constructions + Point::deplacements) << "\n";
    #endif

    return 0;
}
