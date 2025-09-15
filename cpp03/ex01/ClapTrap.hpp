#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class ClapTrap  // The class
{
    protected: // protected makes it private but accesible for inherited classes this way Scavtrap doesnt need new variables
        std::string _name;
        int _hitpoints;
        int _energypoints;
        int _attackdamage;
    public:             
        // ClapTrap(std::string name, int hpoints, int energy, int ad); //default constructor
        ClapTrap(std::string name); //default constructor
        ClapTrap(const ClapTrap &other); //copy constructor

        ClapTrap &operator=(const ClapTrap &other); //copy assignment operator

        
        virtual ~ClapTrap(); // virtual destructor to ensure proper destruction of inherited classes with pointers

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif