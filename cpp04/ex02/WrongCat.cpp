#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Default WrongCat constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    // _type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "MIAUUU!" << std::endl;
}

std::string WrongCat::getType(void) const
{
    return (this->_type);
}