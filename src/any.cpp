#include <iostream>
#include <string>
#include <any>

// $ g++ -std=c++17 any.cpp

using namespace std;

int main()
{
    any a = 1;
    cout << a.type().name() << " -> " << any_cast<int>(a) << '\n';
    
    any s = string("Hello world!");
    cout << s.type().name() << " -> " << any_cast<string>(s) << '\n';

    return 0;
}
