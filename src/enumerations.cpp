#include <iostream>

using namespace std;

int main()
{
    /*
    // Problème n°1 : Deux énumérations ne peuvent pas partager les mêmes noms
    enum Genre { Masculin, Femimin };
    enum GenrePersonne { Masculin, Femimin }; // error: redeclaration of 'Masculin'
    
    Genre genre = Masculin; 
    GenrePersonne genrePersonne = Femimin; 
  
    cout << "genre = " << genre << endl;
    cout << "genrePersonne = " << genrePersonne << endl;

    // Problème n°2 : Aucune variable ne peut avoir un nom déjà utilisé dans une énumération
    int Masculin = 10; // error: 'int Masculin' redeclared as different kind of symbol

    cout << "Masculin = " << Masculin << endl;

    // Problème n°3 : Les énumérations ne sont pas un type complétement sécurisé (un simple warning !)
    enum Couleur { Rouge, Vert, Bleu };

    Couleur couleur = Rouge; 

    if (genre == couleur) //warning: comparison between 'enum main()::Genre' and 'enum main()::Couleur'
        cout << "Égal !";
    */

    enum class Genre { Masculin, Femimin };
    enum class GenrePersonne { Masculin, Femimin };
    
    Genre genre = Genre::Masculin; 
    GenrePersonne genrePersonne = GenrePersonne::Femimin; 
  
    cout << "genre = " << int(genre) << endl;
    cout << "genrePersonne = " << int(genrePersonne) << endl;

    int Masculin = 10;

    cout << "Masculin = " << Masculin << endl;

    /*enum class Couleur { Rouge, Vert, Bleu };

    Couleur couleur = Couleur::Rouge; 

    if (genre == couleur) // error: no match for 'operator==' (operand types are 'main()::Genre' and 'main()::Couleur')
        cout << "Égal !";*/

    return 0;
}
