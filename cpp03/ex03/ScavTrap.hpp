#ifndef SCLAVTRAP_HPP
#define SCLAVTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap //making it virtual so that it doesnt create another claptrap when creating a diamontrap
{
    private:
        // std::string _name;
        // int _hitpoints;
        // int _energypoints;
        // int _attackdamage;
        // ClapTrap::ClapTrap; // error inheriting constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
        // void takeDamage(unsigned int amount); // removed so that it doesnt become ambiguous for diamondtrap to use this ones, just inherit from claptrap
        // void beRepaired(unsigned int amount);
};
#endif