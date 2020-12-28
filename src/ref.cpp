#include <iostream>
#include <functional>
#include <thread>

using namespace std;

// La fonction std::ref retourne un objet de type std::reference_wrapper<T> qui est en fait une référence sur l'élément.
// http://www.cplusplus.com/reference/functional/ref/

// $ g++ ref.cpp -lpthread

void foo(int& data)
{
    data = 42;
}

int main()
{
    int i1 = 100;
    cout << "i1 = " << i1 << endl;
    
    foo(std::ref(i1));
    cout << "i1 = " << i1 << endl;

    i1 = 100;
    cout << "i1 = " << i1 << endl;
    //std::thread t1(foo, i1); // no works
    std::thread t1(foo, std::ref(i1));  // works

    t1.join();
    cout << "i1 = " << i1 << endl;

    return 0;
}
