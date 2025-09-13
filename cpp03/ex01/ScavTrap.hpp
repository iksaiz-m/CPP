#ifndef SCLAVTRAP_HPP
#define SCLAVTRAP_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "ClapTrap.hpp"

// class ClapTrap  // The class
// {
//     private: 
//         std::string _name;
//         int _hitpoints;
//         int _energypoints;
//         int _attackdamage;
//     public:             
//         ClapTrap(std::string name); //default constructor
//         ClapTrap(const ClapTrap &other); //copy constructor

//         ClapTrap &operator=(const ClapTrap &other); //copy assignment operator

        
//         ~ClapTrap(); // destrcutor

//         void attack(const std::string& target);
//         void takeDamage(unsigned int amount);
//         void beRepaired(unsigned int amount);
// };
class ScavTrap : public ClapTrap 
{
    private:
        std::string _name;
        int _hitpoints;
        int _energypoints;
        int _attackdamage;
        // ClapTrap::ClapTrap; // error inheriting constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif