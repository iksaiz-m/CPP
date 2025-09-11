#include "Fixed.hpp"

Fixed::Fixed() 
{
    std::cout << "Default constructor called" << std::endl;
    _fixed = 0;
}

Fixed::Fixed(int number)
{
    std::cout << "Int constructor called" << std::endl;
    _fixed = number;
}

Fixed::Fixed(const float fnumber)
{
    std::cout << "Float constructor called" << std::endl;
    _fixed = roundf(fnumber);
}

float Fixed::toFloat(void) const
{
    return ((float)_fixed);
}

int Fixed::toInt(void) const
{
    return ((int)_fixed);
}


Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    _fixed = other._fixed;
}


Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        _fixed = other._fixed;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}
void Fixed::setRawBits(int const raw)
{
    _fixed = raw;
}