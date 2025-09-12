#include "ClapTrap.hpp"

int main()
{
    ClapTrap robotin("Claptrap", 10, 10, 0);
    ClapTrap paco("Manolo", 10, 10, 0);
    robotin.attack("Manolo");
}