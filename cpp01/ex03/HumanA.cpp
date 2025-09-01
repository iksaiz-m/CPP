#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}


std::string HumanA::getname(void) const
{
    return (this->_name);
}

Weapon HumanA::getWeapon() const
{
    return (this-> _weapon);
}

// void HumanA::setWeapon(Weapon Weapon)
// {
//     _weapon = Weapon;
// }


void HumanA::attack()
{
    std::cout << getname() << " attacks with their " << getWeapon().getType() << std::endl;
}
