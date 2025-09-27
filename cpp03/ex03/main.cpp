#include "DiamondTrap.hpp"
// #include "ClapTrap.hpp"
// #include "ScavTrap.hpp"
// #include "FragTrap.hpp"

int main()
{
    // ClapTrap robotin("Claptrap");
    DiamondTrap paletin("maonolo");
    DiamondTrap jaime(paletin);
    // DiamondTrap juan;
    // DiamondTrap f1("Pepe");
    // FragTrap f2("Juan");
    
    //f2 = f1;
    /* this will compile and work properly because diamondtraps are fragtraps 
    so are lower in hierarchy claptrap-->fragtrap/scavtrap-->diamondtraps*/

    //f1 = f2;
    /* this wont compile or work because fragtraps are not diamondtraps
    error: no match for ‘operator=’ (operand types are ‘DiamondTrap’ and ‘FragTrap’)*/
    // juan.whoAmI();
    // jaime.attack("Manolo");
    // paletin.attack("Manolo");
    // paletin.attack("Manolo");
    // paletin.takeDamage(115);
    // // paletin.beRepaired(10);
    // paletin.attack("Manolo");
    // jaime.highFivesGuys();
    jaime.whoAmI();
}