#include <iostream>

using namespace std;

class Nombre
{
    public:
        Nombre(int nombre) : nombre(nombre) {}
        Nombre() : Nombre(42) {}
        int getNombre() const { return nombre; }

    private:
        int nombre;
};

int main()
{
    Nombre n1;
    Nombre n2(2);

    cout << "n1 = " << n1.getNombre() << endl;
    cout << "n2 = " << n2.getNombre() << endl;

    return 0;
}
