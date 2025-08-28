#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class Zombie  // The class
{
    private: // Access specifier
        std::string _name;  // Attributos (strings con  _ porque son privadas)
    public:             // Access specifier
        // Zombie(std::string name);
        Zombie();
        ~Zombie();
        void announce( void );
        void setName(const std::string& name);
        std::string getname() const;
};
    // void randomChump(std::string name);
    // Zombie* newZombie(std::string name);
    Zombie* zombieHorde(int N, std::string name);
#endif