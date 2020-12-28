#include <iostream>
#include <string>
#include <optional>

// $ g++ -std=c++17 optional.cpp

using namespace std;

class Article
{
    public:
        Article(const string& libelle) : libelle(libelle) {}
        Article(const string& libelle, optional<double> prix) : libelle(libelle), prix(prix) {}
        string getLibelle() const { return libelle; }
        optional<double> getPrix() const {
            if(prix.has_value())
                return prix;
            else
                return {};
        }
    private:
        string libelle;
        optional<double> prix;
};

int main()
{
    Article article1("De'Longhi Magnifica S", 295.0);
    Article article2("Philips EP2220");

    cout << "Article " << article1.getLibelle() << endl;
    auto prix1 = article1.getPrix();
    if (prix1.has_value())
    {
        cout << "  prix : " << prix1.value() << " euros" << endl;
    }
    else
    {
        cout << "  pas de prix pour cet article" << endl;
    }

    cout << "Article " << article2.getLibelle() << endl;
    auto prix2 = article2.getPrix();
    if (prix2.has_value())
    {
        cout << "  prix : " << prix2.value() << " euros" << endl;
    }
    else
    {
        cout << "  pas de prix pour cet article" << endl;
    }

    return 0;
}
