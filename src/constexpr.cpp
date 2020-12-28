#include <iostream>

using namespace std;

constexpr size_t getTaille()
{
    return 10;
}

constexpr size_t getTaille(int n)
{
    return 10*n;
}

int main()
{
    constexpr float x = 42.0;    
    constexpr int N = 5;
    
    int t1[N] = { 1, 2, 3, 4, 5 }; // 5 x 4
    int t2[getTaille()];  // 10 x 4
    int t3[getTaille(2)];  // 2 x 10 x 4

    cout << "taille t1 = " << sizeof(t1) << " octets" << endl;
    cout << "taille t2 = " << sizeof(t2) << " octets" << endl;
    cout << "taille t3 = " << sizeof(t3) << " octets" << endl;

    return 0;
}
