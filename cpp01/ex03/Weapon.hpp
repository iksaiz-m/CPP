#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class Weapon  // The class
{
    private: // Access specifier
        std::string _type;
    public:             // Access specifier
        Weapon(std::string type);
        ~Weapon();
        void setType(const std::string& type);
        std::string getType() const;
};
#endif