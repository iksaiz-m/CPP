#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap robotin("Claptrap");
    ScavTrap paletin("maonolo");
    ScavTrap x(paletin);
    x.attack("Manolo");
    x.attack("Manolo");
    x.attack("Manolo");
    paletin.attack("Manolo");
    paletin.takeDamage(85);
    paletin.beRepaired(2150145135);
    paletin.takeDamage(2);
    paletin.beRepaired(1);
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