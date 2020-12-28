#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Exemple 1
    auto lambda = [](string const & message) -> void { cout << "Message reçu : " << message << endl; };
    
    lambda("Hello !");

    // Exemple 2
    vector<string> const chaines { "Un mot", "Autre chose", "Du blabla", "Du texe", "Des lettres" };

    for_each(begin(chaines), end(chaines), [](string const & message) -> void
    {
        cout << "Message reçu : " << message << endl;
    });

    // Exemple 3
    vector<int> v { 1,2,3,4,5,6,7 };

    cout << "v : ";
    for (auto i: v) // i est un int
    {
        cout << i << ' ';
    }
    cout << '\n';

    unsigned int nbElementsPairs = 0;

    nbElementsPairs = count_if(v.begin(), v.end(), [](auto x) { return !(x % 2); });
    cout << "nbElementsPairs : " << nbElementsPairs << endl;

    // Exemple 4
    int borneMax = 5;
    unsigned int nbElements = 0;

    // accès aux variables par référence [&]
    nbElements = count_if(v.begin(), v.end(), [&](auto x) { return (x <= borneMax); });
    cout << "nbElements : " << nbElements << endl;

    borneMax = 4;

    // accès aux variables par copie [=]
    nbElements = count_if(v.begin(), v.end(), [=](auto x) { return (x <= borneMax); });
    cout << "nbElements : " << nbElements << endl;
    
    return 0;
}
