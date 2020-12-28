#include <vector>
#include <iostream>

using namespace std;
 
int main()
{
    std::vector<int> v { 1,2,3,4,5,6,7 };
 
    cout << "v : ";
    for (auto it=v.begin(); it != v.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';

    // ou avec range-for
    std::cout << "v : ";
    for (auto i: v)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
