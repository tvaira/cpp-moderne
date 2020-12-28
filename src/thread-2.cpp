#include <iostream>
#include <thread>
#include <chrono>

// $ g++ thread-2.cpp -lpthread

using namespace std;

void etoile()
{
    for(int i=0; i < 10; ++i)
    {
        this_thread::sleep_for(chrono::duration<int,milli>(250));
        cout << "*";
    }
}

void diese()
{
    for(int i=0; i < 10; ++i)
    {
        this_thread::sleep_for(chrono::duration<int,milli>(250));
        cout << "#";
    }
}

int main()
{
    setbuf(stdout, NULL);
    
    thread t1(etoile); // création et lancement du thread
    thread t2(diese); // création et lancement du thread

    t1.join(); // attendre la fin du thread
    t2.join(); // attendre la fin du thread

    cout << endl;

    return 0;
}
