#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal Copy constructor called" << std::endl;
    _type = other._type;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "AAnimal Copy assignment operator called" << std::endl;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal thinks before it makes a sound" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->_type);
}