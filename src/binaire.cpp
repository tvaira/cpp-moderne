#include <iostream>

using namespace std;

int main()
{
    int i = 0b0101'0101;
    int j = 0B1010'1010;

    cout << "i = " << i << " (0x" << hex << i << ")" << endl;
    cout << "j = " << j << " (0x" << hex << j << ")" << endl;

    return 0;
}
