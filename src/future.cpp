#include <iostream>
#include <future> // pour async et future
#include <chrono>

// $ g++ future.cpp -lpthread

using namespace std;

// la factorielle d'un entier naturel n est le produit des nombres entiers strictement positifs inférieurs ou égaux à n
long factorielle(long n)
{
    return n > 1 ? (n * factorielle(n-1)) : 1; // https://fr.wikipedia.org/wiki/Factorielle#Algorithme
}

// exemple : http://www.cplusplus.com/reference/future/future/
bool is_prime(int x)
{
    // version non optimisée
    for (int i=2; i<x; ++i)
    {
        if (x%i == 0)
            return false;
    }
  
    return true;
}

int main()
{
    // future permet de lancer une fonction de manière asynchrone et
    // d'en récupérer le résultat
    long n = 15;
    future<long> resultat1 = async(factorielle, n);

    cout << "veuillez patienter pendant le calcul de la factorielle de " << n;
    chrono::milliseconds tempo(100);
    while (resultat1.wait_for(tempo)==future_status::timeout)
        cout << '.' << flush;
    cout << '\n';
    
    cout << "résultat : " << resultat1.get() << "\n";

    future<bool> resultat2 = async(is_prime, 444444443);

    cout << "veuillez patienter pendant la vérification";
    while (resultat2.wait_for(tempo)==future_status::timeout)
        cout << '.' << flush;
    cout << '\n';

    cout << "444444443 " << (resultat2.get() ? "est" : "n'est pas") << " premier.\n";

    return 0;
}
