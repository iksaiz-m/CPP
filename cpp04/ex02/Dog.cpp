#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "Default Dog constructor called" << std::endl;
    _type = "Dog";
    Brain = new class Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
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
    delete (Brain);
}

void Dog::makeSound() const
{
    std::cout << "GUAU" << std::endl;
}

std::string Dog::getType(void) const
{
    return (this->_type);
}