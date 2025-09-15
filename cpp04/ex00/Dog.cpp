#include "Dog.hpp"

Dog::Dog() : Animal()
{
        std::cout << "Default Dog constructor called" << std::endl;
        _type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    // _type = other._type;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "GUAU" << std::endl;
}

std::string Dog::getType(void) const
{
    return (this->_type);
}