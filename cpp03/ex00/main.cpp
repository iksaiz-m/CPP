#include "ClapTrap.hpp"

int main()
{
    ClapTrap robotin("Claptrap");
    ClapTrap a("pepe");
    a = robotin;
    robotin.attack("Manolo");
    robotin.attack("Manolo");
    robotin.attack("Manolo");
    robotin.attack("Manolo");
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.takeDamage(2147483757);
    robotin.takeDamage(3147);
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.beRepaired(1);
    robotin.attack("Manolo");
    robotin.beRepaired(1);
}
// && amount < 2147483647