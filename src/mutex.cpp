#include <iostream>
#include <thread>
#include <mutex>

// Chaque thread (tache) va faire ses COUNT boucles
#define COUNT  5000

//#define MUTEX // avec ou sans mutex

using namespace std;

int value_globale = 1;

#ifdef MUTEX
mutex m;
#endif

// Avec mutex : g++ mutex.cpp -DMUTEX -lpthread
// Sans mutex : g++ mutex.cpp -lpthread

void increment()
{    
    int value = 0;
    
    for(int i=0; i < COUNT; ++i)
    {
        #ifdef MUTEX
        m.lock();
        #endif
        
        // Récupère la value
        value = value_globale;

        // Incrémente la value
        value += 1;

        // Stocke la value
        value_globale = value;

        #ifdef MUTEX
        m.unlock();
        #endif
    }
}

void decrement()
{
    int value = 0;
    
    for(int i=0; i < COUNT; ++i)
    {
        #ifdef MUTEX
        m.lock();
        #endif
        
        // Récupère la value
        value = value_globale;

        // Décrémente la value
        value -= 1;

        // Stocke la value
        value_globale = value;

        #ifdef MUTEX
        m.unlock();
        #endif
    }
}

int main()
{
    setbuf(stdout, NULL);

    cout << "Avant l'exécution des threads : value = "<< value_globale << " (" << COUNT << " boucles)\n";
    
    thread t1(increment); // création et lancement du thread
    thread t2(decrement); // création et lancement du thread

    t1.join(); // attendre la fin du thread
    t2.join(); // attendre la fin du thread

    cout << "\nApres l'exécution des threads : value = "<< value_globale << " (" << COUNT << " boucles)\n";

    return 0;
}
