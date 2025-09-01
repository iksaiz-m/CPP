#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB  // The class
{
    private: // Access specifier
        std::string _name;  // Attributos (strings con  _ porque son privadas)
        Weapon* _weapon; // pointer to weapon can be null or changed
    public:             // Access specifier
        HumanB(std::string name); // class without a weapon in constructor, weapon set to null
        ~HumanB();

        void setWeapon(Weapon &Weapon);
        Weapon* getWeapon() const; // can be done because it is a pointer
        void attack();
        std::string getname() const;
};
#endif