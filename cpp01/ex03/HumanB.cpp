#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : _name(name), _weapon(NULL) {} // weapon initialized to null 

HumanB::~HumanB() {}

std::string HumanB::getname(void) const
{
    return (this->_name);
}

Weapon* HumanB::getWeapon() const // returns the pointer to the weapon
{
    return (this-> _weapon);
}

void HumanB::setWeapon(Weapon &Weapon)
{
    _weapon = &Weapon;
}

void HumanB::attack()
{
    if (getWeapon() != NULL) // checks if weapon has been given or the pointer is still at null from the constructor
        std::cout << getname() << " attacks with their " << getWeapon()->getType() << std::endl;
    else
        std::cout << getname() << " Is unarmed!" << std::endl;
}
