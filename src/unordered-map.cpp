#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, string> hashtable;

    //hashtable.emplace("www.wikipedia.fr", "78.109.84.114");
    //cout << "Adresse IP : " << hashtable["www.wikipedia.fr"] << endl;

    hashtable.insert(make_pair("www.cplusplus.com", "167.114.170.15"));
    hashtable.insert(make_pair("www.google.fr", "216.58.204.67"));
    cout << "Adresse IP de www.google.fr : " << hashtable["www.google.fr"] << endl << endl;
 
    cout << "La  table : " << endl;
    for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++)
    {
        cout << (*itr).first << " -> " << (*itr).second << endl;
    }
 
    return 0;
}
