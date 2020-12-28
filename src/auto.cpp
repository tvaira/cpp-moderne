#include <iostream>

using namespace std;

int main()
{
    auto booleen = false; // bool
    auto ch = 'c'; // char
    auto i = 10; // int
    auto f = 1.5; // double
    auto s = "string"; // char *

    cout << "booleen = " << booleen << " (" << sizeof(booleen) << " octet)" << endl;
    cout << "ch = " << ch << " (" << sizeof(ch) << " octet)" << endl;
    cout << "i = " << i << " (" << sizeof(i) << " octets)" << endl;
    cout << "f = " << f << " (" << sizeof(f) << " octets)" << endl;
    cout << "s = " << s << " (" << sizeof(s) << " octets)" << endl;

    return 0;
}
