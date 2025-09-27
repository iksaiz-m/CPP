#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class ClapTrap  // The class
{
    private: 
        std::string _name;
        int _hitpoints;
        int _energypoints;
        int _attackdamage;
    public:
        ClapTrap(); //default constructor
        ClapTrap(std::string name); //constructor with parameters
        ClapTrap(const ClapTrap &other); //copy constructor

        ClapTrap &operator=(const ClapTrap &other); //copy assignment operator

        
        ~ClapTrap(); // destrcutor

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif