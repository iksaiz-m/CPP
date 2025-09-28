#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class ClapTrap  // The class
{
    protected: // protected makes it private but accesible for inherited classes
        std::string _name;
        int _hitpoints;
        int _energypoints;
        int _attackdamage;
    public:             
        // ClapTrap(std::string name, int hpoints, int energy, int ad); //default constructor
        ClapTrap();
        ClapTrap(std::string name); 
        ClapTrap(const ClapTrap &other);

        ClapTrap &operator=(const ClapTrap &other);

        
        virtual ~ClapTrap(); // virtual destructor

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif

