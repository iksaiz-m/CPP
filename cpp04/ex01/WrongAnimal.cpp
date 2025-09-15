#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    _type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal creaks" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}