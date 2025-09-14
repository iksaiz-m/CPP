#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap //making it virtual so that it doesnt create another claptrap when creating a diamontrap
{
    private:
        // std::string _name;
        // int _hitpoints;
        // int _energypoints;
        // int _attackdamage;
        // ClapTrap::ClapTrap; // error inheriting constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();
        void highFivesGuys(void);
        void attack(const std::string& target);
        // void takeDamage(unsigned int amount); // removed so that it doesnt become ambiguous for diamondtrap to use this ones, just inherit from claptrap
        // void beRepaired(unsigned int amount);
};
#endif