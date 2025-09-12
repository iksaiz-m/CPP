#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, int hpoints, int energy, int ad)
{
        std::cout << "Default constructor called" << std::endl;
    _name = name;
    _hitpoints = hpoints;
    _energypoints = energy;
    _attackdamage = ad;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
        *this = other;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

        
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        // target.takeDamage(_attackdamage);
        _energypoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackdamage << " points of damage!" << std::endl;
        std::cout << "ClapTraps energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << "no energy to perform actions" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    _hitpoints = _hitpoints - amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        _hitpoints = _hitpoints + amount;
        _energypoints--;
        std::cout << "ClapTrap " << _name << " repairs " << amount << " points of damage!" << std::endl;
        std::cout << "ClapTraps energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << "no energy to perform actions" << std::endl;
}