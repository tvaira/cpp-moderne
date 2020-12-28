#include <iostream>
#include <cstddef>

using namespace std;

// g++ -std=c++17 byte.cpp

int main()
{
    byte b1{ 10 };
    byte b2{ 21 };
    cout << "b1 = " << to_integer<int>(b1) << endl;
    b2 <<= 1;
    cout << "b2 = " << to_integer<int>(b2) << endl;

    byte b3 = b1 & b2;
    cout << "b3 = b1 & b2" << endl;
    cout << "b3 = " << to_integer<int>(b3) << endl;
    
    int i1 = to_integer<int>(b3);
    cout << "i1 = " << i1 << endl;

    return 0;
}
