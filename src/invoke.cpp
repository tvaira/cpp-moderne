#include <iostream>
#include <string>
#include <functional>

//$ g++ -std=c++17 invoke.cpp

using namespace std;

class Foo
{
    public:
        Foo(const string& str) : str(str) {}
        void print(int n=1) const { for(int i = 0; i<n; ++i) cout << str << '\n'; }
    private:
        string str;
};

void print(string str)
{
    cout << "message : " << str << endl;
}

int main()
{
    // fonction
    invoke(print, "Hello world!");

    const Foo foo("Hello world!");

    // méthode
    invoke(&Foo::print, foo, 2);

    return 0;
}
