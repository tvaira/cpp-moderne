#include <iostream>

using namespace std;

void foo(int& x)
{
    cout << "foo(int x) -> " << x << endl;
}

void foo(int&& x)
{
    cout << "foo(int&& x) -> " << x << endl;
}

int main()
{
    int a = 2; // a est une lvalue
    int& ra = a; // ra est une référence sur la lvalue a
    
    cout << "a = " << a << endl;
    cout << "ra = " << ra << endl;
    cout << endl;

    int&& rvb = 42; // rvb est une référence sur une rvalue
    cout << "rvb = " << rvb << endl;

    int&& rva = move(a); // rva est une référence sur une rvalue
    cout << "rva = " << rva << endl;
    cout << endl;

    int b = 2;

    foo(b); // passage d'une lvalue

    foo(42); // passage d'une rvalue

    foo(static_cast<int&&>(b)); // la lvalue b est castée en référence rvalue

    foo(move(b)); // move() retourne une référence rvalue sur 'b'

    return 0;
}
