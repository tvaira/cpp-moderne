#include <iostream>
#include <array>

#define TAILLE  3

using namespace std;

int main()
{
    // En C/C++
    cout << "-> En C/C++" << endl;
    
    int t1[TAILLE] = {10, 20, 30};

    cout << "Elements du tableau t1 (avant) : " << endl;
    for (int i=0; i<TAILLE; ++i)
        cout << t1[i] << " ";
    cout << endl;
    
    for (int i=0; i<TAILLE; ++i)
        ++t1[i];

    cout << "Elements du tableau t1 (après) : " << endl;
    for (int i=0; i<TAILLE; ++i)
        cout << t1[i] << " ";
    cout << endl;

    cout << "Elements du tableau t1 (après) : " << endl;
    for (int element : t1)
        cout << element << " ";
    cout << endl;

    cout << endl;

    // En C++11
    cout << "-> En C++11" << endl;
    
    array<int,TAILLE> t2 {10, 20, 30};

    cout << "Elements du tableau t2 (avant) : " << endl;
    for (int i=0; i<t2.size(); ++i)
        cout << t2[i] << " ";
    cout << endl;

    for (int i=0; i<t2.size(); ++i)
        ++t2[i];

    cout << "Elements du tableau t2 (après) : " << endl;
    for (int i=0; i<t2.size(); ++i)
        cout << t2[i] << " ";
    cout << endl;

    cout << "Elements du tableau t2 (après) : " << endl;
    for (int element : t2)
        cout << element << " ";
    cout << endl;

    // Avec un pointeur
    int *t3 = t2.data(); // data() renvoie un pointeur vers le premier élément du tableau

    // Dans array, les éléments du tableau sont stockés dans des emplacements mémoire contigus,
    // le pointeur récupéré ici t3 peut être utilisé pour accéder à n'importe quel élément du tableau.
    cout << "Elements du tableau t2 (avec un pointeur) : " << endl;
    for (int i=0; i<TAILLE; ++i)
        cout << t3[i] << " "; // cout << *(t3+i) << " ";
    cout << endl;

    // Avec un itérateur
    cout << "Elements du tableau t2 (avec un itérateur) : " << endl;
    //for(array<int,TAILLE>::iterator it = t2.begin(); it != t2.end(); ++it)
    for(auto it = t2.begin(); it != t2.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
