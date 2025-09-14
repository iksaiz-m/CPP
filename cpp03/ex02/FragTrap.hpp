#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
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
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif