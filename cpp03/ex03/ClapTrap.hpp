#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class ClapTrap  // The class
{
    protected: 
        // std::string _name;
        // int _hitpoints;
        // int _energypoints;
        // int _attackdamage;
        std::string _name;
        int _hitpoints;
        int _energypoints;
        int _attackdamage;
    public:             
        // ClapTrap(std::string name, int hpoints, int energy, int ad); //default constructor
        ClapTrap(std::string name); //default constructor
        ClapTrap(const ClapTrap &other); //copy constructor

        ClapTrap &operator=(const ClapTrap &other); //copy assignment operator

        
        virtual ~ClapTrap(); // destrcutor

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif