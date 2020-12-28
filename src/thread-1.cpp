#include <iostream>
#include <thread>

// $ g++ thread-1.cpp -lpthread

using namespace std;

void unThread() { cout << "Hello !" << endl; }

int main()
{
    thread hello(unThread); // création et lancement du thread

    hello.join(); // attendre la fin du thread

    return 0;
}
