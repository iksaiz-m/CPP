#ifndef SCLAVTRAP_HPP
#define SCLAVTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap //inherits from claptrap
{
    private:
        // ClapTrap::ClapTrap; // error inheriting constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif