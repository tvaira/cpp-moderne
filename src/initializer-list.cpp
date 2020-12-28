#include <vector>
#include <iostream>

using namespace std;

template <class T> class MonVecteur
{
    public:
        MonVecteur(initializer_list<T> liste) : v(liste) {}
        void append(std::initializer_list<T> liste)
        {
            v.insert(v.end(), liste.begin(), liste.end());
        }    
    //private:
        vector<T> v;
};
 
int main()
{
    MonVecteur<int> v = {1, 2, 3, 4, 5};
    v.append({6, 7, 8});
 
    std::cout << "v : ";
    for (auto i: v.v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
