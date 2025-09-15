#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "Default Cat constructor called" << std::endl;
    _type = "Cat";
    Brain = new class Brain();

}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete (Brain);
}

void Cat::makeSound() const
{
    std::cout << "MIAUUU!" << std::endl;
}

std::string Cat::getType(void) const
{
    return (this->_type);
}
