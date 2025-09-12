#include "ClapTrap.hpp"

int main()
{
    ClapTrap robotin("Claptrap", 10, 10, 0);
    robotin.attack("Manolo");
    robotin.attack("Manolo");
    robotin.attack("Manolo");
    robotin.attack("Manolo");
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.beRepaired(1);

}