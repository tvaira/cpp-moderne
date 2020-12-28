#include <iostream>
#include <string>
#include <functional>

using namespace std;

void foo(string str)
{
    cout << "message : " << str << endl;
}

int main()
{
    std::function<void(string)> fn_foo = foo;

    fn_foo("Hello world!");

    return 0;
}
