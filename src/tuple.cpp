#include <iostream>
#include <tuple> // cf. http://www.cplusplus.com/reference/tuple/tuple/

using namespace std;
 
int main()
{
    typedef tuple<string, string, int, double> tuple_1;
    tuple_1 foo("John", "Smith", 50, 1.87);
    cout << get<0>(foo) << " " << get<1>(foo) << endl;
    cout << "Nb elements du tuple : " << tuple_size<tuple_1>::value << endl;
    
    tuple<double, double, char> p1(0., 0. ,'A');
    cout << get<2>(p1) << " : " << get<0>(p1) << "," << get<1>(p1) << endl;
    get<2>(p1) = 'B';
    cout << get<2>(p1) << " : " << get<0>(p1) << "," << get<1>(p1) << endl;

    auto bar = std::make_tuple("pi", 3.14);
    cout << get<0>(bar) << " = " << get<1>(bar) << endl;

    return 0;
}
