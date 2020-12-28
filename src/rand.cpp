#include <iostream>
#include <random>
#include <functional>   // std::bind
#include <chrono>

using namespace std;
 
int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    
    std::uniform_int_distribution<int> distribution1(1, 6); // un dé à 6 faces
    std::default_random_engine default_engine(seed);

    int de = distribution1(default_engine);  // genere un nombre entre 1 et 6
    cout << "de = " << de << '\n';

    std::uniform_int_distribution<int> distribution2(0, 99);
    std::mt19937 engine(seed);
    auto generator = std::bind(distribution2, engine);
    
    int random = generator();  // genere un nombre entre 0 et 99
    cout << "random = " << random << '\n';

    return 0;
}
