#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
        std::cout << "Default ClapTrap constructor called" << std::endl;
    _name = name;
    _hitpoints = 10;
    _energypoints = 10;
    _attackdamage = 0;
}

// ClapTrap::ClapTrap(std::string name)
// {
//         std::cout << "Default constructor called" << std::endl;
//     _name = name;
// }

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
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        // target.takeDamage(_attackdamage);
        _energypoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
        std::cout << "ClapTraps energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << _name << " has no energy or hp to perform actions" << std::endl;
}
// void ClapTrap::takeDamage(unsigned int amount)
// {
//     if (_hitpoints > 0)
//     {
//         std::cout << (_hitpoints - amount) << std::endl;
//         _hitpoints = _hitpoints - amount;
//         std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
//     }
//     else
//     {
//         std::cout << "ClapTrap " << _name << " cant take more damage" << std::endl;
//         _hitpoints = 0;
//     }
// }

void ClapTrap::takeDamage(unsigned int amount)
{
    int norevival;

    norevival = amount - 2147483647;
    if (_hitpoints > 0)
    {
        if (_hitpoints > norevival)
            _hitpoints = _hitpoints - amount;
        else
            _hitpoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " cant take more damage" << std::endl;
        _hitpoints = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    int noinstadeath;

    noinstadeath = _hitpoints + amount;
    if (_energypoints > 0 && _hitpoints > 0)
    {
        if (noinstadeath > 0)
        {
            _hitpoints = noinstadeath;
            std::cout << "ClapTrap " << _name << " repairs " << amount << " points of damage!" << std::endl;
        }
        else
        {
            std::cout << "ClapTrap " << _name << " repaired until it couldnt repair anymore" << std::endl;
            _hitpoints = 2147483647;
        }
        _energypoints--;
        std::cout << "ClapTraps energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << _name << " has no energy or hp to perform actions" << std::endl;
}