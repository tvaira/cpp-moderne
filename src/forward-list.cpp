#include <iostream>
#include <forward_list>

using namespace std;

int main()
{  
    forward_list<int> liste = {10, 20, 30, 40, 50};

    cout << "liste :\n";
    for (int& element : liste)
        cout << element << " ";
    cout << '\n';

    return 0;
}
