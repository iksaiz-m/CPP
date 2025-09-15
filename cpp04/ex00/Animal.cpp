#include "Animal.hpp"

Animal::Animal()
{
        std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    _type = other._type;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal thinks before it makes a sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}