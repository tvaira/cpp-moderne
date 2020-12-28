#include <iostream>

using namespace std;

class X
{
    public:
        X() : x(0) {}
        int getX() const { return x; };
        void foo() const;

    private:
        mutable int x = 0;
};

void X::foo() const
{
    ++x;
}
 
int main()
{
    X unObjetX;

    cout << "x = " << unObjetX.getX() << endl;
    
    unObjetX.foo();

    cout << "x = " << unObjetX.getX() << endl;

    return 0;
}
