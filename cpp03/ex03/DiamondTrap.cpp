#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) // inherit from all classes in order
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    DiamondTrap::_name = name; // Giving him a name to make it different from the Claptrap name
    _hitpoints = FragTrap::_hitpoints; //inherit hp
    _energypoints = ScavTrap::_energypoints; //inherit ep
    _attackdamage = FragTrap::_attackdamage; //inherit ad
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) //inherits from all classes in order
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
        *this = other;
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target); //it calls the same function from ScavTrap
}

void DiamondTrap::whoAmI()
{
    std::cout << "my name is " << DiamondTrap::_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
    //diferente name between this and claptrap name//
}