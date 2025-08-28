#include "Zombie.hpp"

int main()
{

    int n = 3;
    int i = 0;
   Zombie *horde = zombieHorde(n, "pepe");

    while (i < n)
    {
        std::cout << "Zombie: " << i << " ";
        horde[i].announce();
        std::cout << std::endl;
        i++;
    }
    // ZOMBIE->announce();
    delete[] horde;
}