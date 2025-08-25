#include "Zombie.hpp"

Zombie::Zombie(std::string name) 
{
    _name = name;
}
Zombie::~Zombie() 
{
    std::cout << getname() << " is destroyed" <<std::endl;
}


void Zombie::setName(const std::string& name)
{
    _name = name;
}

std::string Zombie::getname(void) const
{
    return (this->_name);
}

void    Zombie::announce(void)
{
    std::cout << getname() << ": BraiiiiiiinnnzzzZ.." <<std::endl;
}
