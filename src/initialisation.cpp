#include <iostream>

using namespace std;

class X
{
public:
    X() {}
    explicit X(int valeur) : valeur(valeur) {}
    int getValeur() const { return valeur; }
	
private:
    int valeur = 1; // pour tous les constructeurs
};

int main()
{
    int a = 10;
    int b = { 20 };
    int c{ 30 };
    int d( 40 );

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << endl;

    auto booleen = false; // bool
    auto ch = 'c'; // char
    auto i = 10; // int
    auto f = 1.5; // double
    auto s = "string"; // char *

    cout << "booleen = " << booleen << " (" << sizeof(booleen) << " octet)" << endl;
    cout << std::boolalpha << "booleen = " << booleen << " (" << sizeof(booleen) << " octet)" << endl;
    cout << "ch = " << ch << " (" << sizeof(ch) << " octet)" << endl;
    cout << "i = " << i << " (" << sizeof(i) << " octets)" << endl;
    cout << "f = " << f << " (" << sizeof(f) << " octets)" << endl;
    cout << "s = " << s << " (" << sizeof(s) << " octets)" << endl;
    cout << endl;

    X x1;
    X x2(2);

    cout << "x1 = " << x1.getValeur() << " (" << sizeof(x1) << " octets)" << endl;
    cout << "x2 = " << x2.getValeur() << " (" << sizeof(x2) << " octets)" << endl;
    //cout << "Membre valeur -> " << sizeof(X::valeur) << " octets" << endl;

    return 0;
}
