#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap //inherits from both (put in constructors in this same order to work)
{
    private:
        std::string _name; //has its own name
        // int _hitpoints;
        // int _energypoints;
        // int _attackdamage;
        // ClapTrap::ClapTrap; // error inheriting constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();
        void whoAmI();
        void attack(const std::string& target);
        // void takeDamage(unsigned int amount);
        // void beRepaired(unsigned int amount);
};
#endif