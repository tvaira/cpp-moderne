#include <iostream>
#include <complex>
#include <chrono>

using namespace std;

class Temperature
{
    private:
        long double temperature = { 0 }; // en celsius
        explicit Temperature(long double valeur) : temperature(valeur) { }
        friend Temperature operator"" _celsius(long double valeur); // pour une valeur en virgule flottante
        friend Temperature operator"" _celsius(unsigned long long valeur); // pour une valeur entière
        friend Temperature operator"" _fahrenheit(long double valeur);
        friend Temperature operator"" _kelvin(long double valeur);

    public:
        constexpr static long double zero_absolu = 273.15; // en celsius
        
        long double celsius() { return temperature; }
        long double fahrenheit() { return (temperature*9./5.) + 32.; }
        long double kelvin() { return (temperature + Temperature::zero_absolu); }
        
        Temperature operator+(Temperature t)
        {
            return Temperature(celsius() + t.celsius());
        }
        friend Temperature operator-(Temperature t);
};

Temperature operator"" _celsius(long double valeur) // pour une valeur en virgule flottante
{
    return Temperature(valeur);
}

Temperature operator"" _celsius(unsigned long long valeur) // pour une valeur entière
{
    return Temperature(double(valeur));
}

Temperature operator"" _fahrenheit(long double valeur)
{
    return Temperature((5./9.) * (valeur - 32.));
}

Temperature operator"" _kelvin(long double valeur)
{
    return Temperature(valeur - Temperature::zero_absolu);
}

Temperature operator-(Temperature t)
{
    return Temperature((-1.) * t.celsius());
}

int main()
{
    complex<double> n = (2.0 + 3.0i) * 4.;

    cout << "n = (2 + 3i) x 4" << endl;
    cout << "n = " << n << endl;
    cout << "partie réelle de n = " << n.real() << endl;
    cout << "partie imaginaire de n = " << n.imag() << endl;
    cout << endl;

    auto recordDuMonde = 2h + 1min + 39s;
    cout << "Record du monde du Marathon : 2 h 01 min 39 s (Eliud Kipchoge en 2018)" << endl;
    cout << "recordDuMonde = " << recordDuMonde.count() << " s" << endl;
    cout << endl;

    Temperature zeroCelsius = 32._fahrenheit; //Temperature zeroCelsius = 0_celsius;
    cout << "zeroCelsius = " << zeroCelsius.celsius() << "C " << zeroCelsius.kelvin() << "K " << zeroCelsius.fahrenheit() << "F " << endl;

    Temperature zeroAbsolu = 0._kelvin;
    cout << "zeroAbsolu = " << zeroAbsolu.celsius() << "C " << zeroAbsolu.kelvin() << "K " << zeroAbsolu.fahrenheit() << "F " << endl;

    Temperature t1 = 36.0_celsius + 42.0_celsius;
    cout << "t1 = 36.0_celsius + 42.0_celsius" << endl;
    cout << "t1 = " << t1.celsius() << "C " << t1.kelvin() << "K " << t1.fahrenheit() << "F " << endl;

    Temperature t2 = 36.0_celsius + -42.0_celsius;
    cout << "t2 = 36.0_celsius + -42.0_celsius" << endl;
    cout << "t2 = " << t2.celsius() << "C " << t2.kelvin() << "K " << t2.fahrenheit() << "F " << endl;

    auto t3 = 36.0_celsius;
    cout << "t3 = " << t3.celsius() << "C " << t3.kelvin() << "K " << t3.fahrenheit() << "F " << endl;

    auto t4 = 36_celsius;
    cout << "t4 = " << t4.celsius() << "C " << t4.kelvin() << "K " << t4.fahrenheit() << "F " << endl;

    //Temperature t5 = 25; // error: conversion from 'int' to non-scalar type 'Temperature' requested
    //Temperature t5 = 25.; // error: conversion from 'double' to non-scalar type 'Temperature' requested
    //Temperature t5 = 36_fahrenheit; // error: unable to find numeric literal operator 'operator""_fahrenheit' -> il faudrait donc surcharger operator"" _fahrenheit(unsigned long long valeur) 

    return 0;
}
