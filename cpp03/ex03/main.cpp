#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    // ClapTrap robotin("Claptrap");
    DiamondTrap paletin("maonolo");
    FragTrap f1("Pepe");
    FragTrap f2("Juan");
    f2 = f1;
    paletin.attack("Manolo");
    paletin.attack("Manolo");
    paletin.attack("Manolo");
    paletin.attack("Manolo");
    paletin.highFivesGuys();
    paletin.whoAmI();
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);
    // robotin.attack("Manolo");
    // robotin.beRepaired(1);

}