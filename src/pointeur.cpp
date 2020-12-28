#include <iostream>

using namespace std;

int main()
{
    int j = 20;
    int *pj = nullptr;

    cout << "j = " << j << " (" << sizeof(j) << " octets)" << endl;
    cout << "&j = " << &j << " (" << sizeof(&j) << " octets)" << endl;
    cout << "pj = " << pj << " (" << sizeof(pj) << " octets)" << endl;
    if(pj != nullptr)
        cout << "*pj = " << *pj << " (" << sizeof(*pj) << " octets)" << endl;

    pj = &j;
    *pj = 30;
    cout << "j = " << j << " (" << sizeof(j) << " octets)" << endl;
    cout << "pj = " << pj << " (" << sizeof(pj) << " octets)" << endl;
    if(pj)
        cout << "*pj = " << *pj << " (" << sizeof(*pj) << " octets)" << endl;

    return 0;
}
