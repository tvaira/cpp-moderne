#include <iostream>
#include <regex>

using namespace std;

int main()
{
    string str = "Le code postal de Sarrians est 84260 et 84000 celui d'Avignon.";
    regex reg {R"(\d{5}?)"};
    smatch matches;

    while (regex_search(str, matches, reg))
    {
        for (auto x:matches) std::cout << x << " ";
        cout << endl;
        //cout << matches.suffix().str() << endl;
        str = matches.suffix().str();
    }

    return 0;
}
