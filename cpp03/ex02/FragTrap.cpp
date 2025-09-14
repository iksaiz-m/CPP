#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) // inherit from claptrap class
{
    std::cout << "Default FragTrap constructor called" << std::endl;
    _hitpoints = 100;
    _energypoints = 100;
    _attackdamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        *this = other;
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        _energypoints--;
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
        std::cout << "FragTrap energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << _name << " has no energy or hp to perform actions" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    int norevival;

    norevival = amount - 2147483647;
    if (_hitpoints > 0)
    {
        if (_hitpoints > norevival)
            _hitpoints = _hitpoints - amount;
        else
            _hitpoints = 0;
        std::cout << "FragTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << _name << " cant take more damage" << std::endl;
        _hitpoints = 0;
    }
}

void FragTrap::beRepaired(unsigned int amount)
{
    int noinstadeath;

    noinstadeath = _hitpoints + amount;
    if (_energypoints > 0 && _hitpoints > 0)
    {
        if (noinstadeath > 0)
        {
            _hitpoints = noinstadeath;
            std::cout << "FragTrap " << _name << " repairs " << amount << " points of damage!" << std::endl;
        }
        else
        {
            std::cout << "FragTrap " << _name << " repaired until it couldnt repair anymore" << std::endl;
            _hitpoints = 2147483647;
        }
            _energypoints--;
        std::cout << "FragTraps energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << _name << " has no energy or hp to perform actions" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (_energypoints > 0 && _hitpoints > 0)
        std::cout <<"FragTrap " << _name << " WANTS TO HIGH FIVES GUYS!!!" << std::endl;
}