#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Foncteur de hachage
class Hachage
{
    public:
        size_t operator()(const string &s) const
        {
            cout << "[hash : " << hash<string>()(s) << "]" << endl;
            return hash<string>()(s);
        }
};

int main()
{
    unordered_map<string, string, Hachage> hashtable;

    hashtable.insert(make_pair("www.wikipedia.fr", "78.109.84.114"));
    hashtable.insert(make_pair("www.cplusplus.com", "167.114.170.15"));
    hashtable.insert(make_pair("www.google.fr", "216.58.204.67"));
 
    cout << endl << "La  table : " << endl;
    for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++)
    {
        cout << (*itr).first << " -> " << (*itr).second << endl;
    }
    cout << endl;
 
    cout << "Adresse IP de www.google.fr : " << hashtable["www.google.fr"] << endl;
 
    return 0;
}
