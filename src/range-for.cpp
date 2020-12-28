#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str = "Hello world!";
    for (char c : str)
    {
        cout << c;
    }
    cout << '\n';

    std::vector<int> v = {0, 1, 2, 3, 4, 5};
 
    for (const auto &i : v) // acces par référence constante
        cout << i << ' ';
    cout << '\n';
 
    for (auto i : v) // acces par valeur (i est de type int)
        cout << i << ' ';
    cout << '\n';

    int t[] = {0, 1, 2, 3, 4, 5};
    for (auto n : t) // avec un tableau
        cout << n << ' ';
    cout << '\n';

    for (auto p : {2, 4, 6}) // avec des constantes
        cout << p << ' ';
    cout << '\n';

    return 0;
}
