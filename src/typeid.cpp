#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Foo
{
    public:
        Foo(const string& str) : str(str) {}
    private:
        string str;
};

int main()
{
    int i = 10;
    int* pi = &i;
    string s = "hello";
    
    cout << "i : " << typeid(i).name() << '\n';
    cout << "&i : " << typeid(&i).name() << '\n';
    cout << "pi : " << typeid(pi).name() << '\n';
    cout << "*pi : " << typeid(*pi).name() << '\n';
    cout << "s : " << typeid(s).name() << '\n';

    auto booleen = false; // bool
    auto f = 1.5; // double

    cout << "booleen : " << typeid(booleen).name() << '\n';
    cout << "f : " << typeid(f).name() << '\n';

    Foo foo(s);
    cout << "foo : " << typeid(foo).name() << '\n';

    return 0;
}
