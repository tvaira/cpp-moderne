#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Foo
{
    public:
        Foo(const string& str) : str(str) {}
        void print(int n=1) const { for(int i = 0; i<n; ++i) cout << str << '\n'; }
    private:
        string str;
};

int main()
{
    const Foo foo("Hello world!");

    auto fn1 = std::mem_fn(&Foo::print);
    fn1(foo, 5);

    return 0;
}
