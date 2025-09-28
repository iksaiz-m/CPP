#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :ClapTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    // _name = "Default";
    _hitpoints = 100;
    _energypoints = 50;
    _attackdamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // inherit from claptrap class
{
    std::cout << "ScavTrap constructor called" << std::endl;
    // _name = name;
    _hitpoints = 100;
    _energypoints = 50;
    _attackdamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) //base class ‘class ClapTrap’ should be explicitly initialized in the copy constructor otherwise it gives an error
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    // *this = other; // not needed it is made with claptrap(other)
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_energypoints > 0 && _hitpoints > 0)
        std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
    else
        std::cout << _name << " has no energy or hp to perform actions" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energypoints > 0 && _hitpoints > 0)
    {
        // target.takeDamage(_attackdamage);
        _energypoints--;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackdamage << " points of damage!" << std::endl;
        std::cout << "ScavTrap energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << _name << " has no energy or hp to perform actions" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    int norevival;

    norevival = amount - 2147483647;
    if (_hitpoints > 0)
    {
        if (_hitpoints > norevival)
            _hitpoints = _hitpoints - amount;
        else
            _hitpoints = 0;
        std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " cant take more damage" << std::endl;
        _hitpoints = 0;
    }
}

void ScavTrap::beRepaired(unsigned int amount)
{
    int noinstadeath;

    noinstadeath = _hitpoints + amount;
    if (_energypoints > 0 && _hitpoints > 0)
    {
        if (noinstadeath > 0)
        {
            _hitpoints = noinstadeath;
            std::cout << "ScavTrap " << _name << " repairs " << amount << " points of damage!" << std::endl;
        }
        else
        {
            std::cout << "ScavTrap " << _name << " repaired until it couldnt repair anymore" << std::endl;
            _hitpoints = 2147483647;
        }
            _energypoints--;
        std::cout << "ScavTraps energypoints left " << _energypoints << std::endl;
    }
    else
        std::cout << _name << " has no energy or hp to perform actions" << std::endl;
}