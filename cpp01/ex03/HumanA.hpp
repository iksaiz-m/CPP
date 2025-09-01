#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA  // The class
{
    private: // Access specifier        
        std::string _name; 
        Weapon& _weapon; // referenced weapon cant be NULL or changed
    public:             // Access specifier
        // HumanA(std::string name, const Weapon& Weapon);
        HumanA(std::string name, Weapon& weapon); // referenced weapon in constructor
        ~HumanA();
        void attack();
        // void setWeapon(Weapon Weapon); // cant be done because it is a reference
        Weapon getWeapon() const;
        std::string getname() const;
};
#endif