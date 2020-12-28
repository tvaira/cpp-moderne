#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Fabricant
{
    private:
        string nom;
    
    public:        
        Fabricant(string nom)
        {
            this->nom = nom;
        }

        string getNom() const
        {
            return nom;
        }

        bool operator==(const Fabricant &f) const
        {
            return nom == f.nom;
        }
};

class Modele
{
    private:
        string nom;
        int annee;

    public:
        Modele(string nom, int annee)
        {
            this->nom = nom;
            this->annee = annee;
        }

        string getNom() const
        {
            return nom;
        }
        
        int getAnnee() const
        {
            return annee;
        }

        bool operator==(const Modele &m) const
        {
            return (nom == m.nom && annee == m.annee);
        }
};

class Hachage
{
    public:
        size_t operator()(const Modele &m) const
        {
            return hash<string>()(m.getNom()) ^ hash<int>()(m.getAnnee());
        }
};

int main()
{
    unordered_map<Modele, Fabricant, Hachage> catalogue;

    Modele zoe("Zoe", 2012);
    Modele megane3("Megane III", 2008);
    Modele clio3("Clio III", 2005);
    Modele bipper("Bipper", 2007);
    Fabricant renault("Renault");
    Fabricant peugeot("Peugeot");

    catalogue.insert(make_pair(zoe, renault));
    catalogue.insert(make_pair(megane3, renault));
    catalogue.insert(make_pair(clio3, renault));
    catalogue.insert(make_pair(bipper, peugeot));
 
    for (auto &itr : catalogue)
    {
        cout << itr.second.getNom() << " " << itr.first.getNom() << " " << itr.first.getAnnee() << endl;
    }

    return 0;
}
