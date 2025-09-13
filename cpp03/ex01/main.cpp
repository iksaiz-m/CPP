#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap robotin("Claptrap");
    ScavTrap paletin("maonolo");
    paletin.attack("Manolo");
    paletin.attack("Manolo");
    paletin.attack("Manolo");
    paletin.attack("Manolo");
    paletin.takeDamage(85);
    paletin.beRepaired(45);
    paletin.takeDamage(777777775);
    paletin.guardGate();
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);

}