#include <iostream>

using namespace std;

struct X
{
   int i;
   double d;
};

int main()
{
    X x;

    decltype(x) y; // le type de y est X
    decltype(x.i) e; // le type de e est int

    return 0;
}
