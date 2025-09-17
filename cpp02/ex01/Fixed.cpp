#include "Fixed.hpp"

Fixed::Fixed() 
{
    std::cout << "Default constructor called" << std::endl;
    _fixed = 0;
}

Fixed::Fixed(int number)
{
    std::cout << "Int constructor called" << std::endl;
     _fixed = number << _fractional_bits; // move _fractional_bits times to the left in this case is like doing * 2^8
}

Fixed::Fixed(const float fnumber)
{
    std::cout << "Float constructor called" << std::endl;
    _fixed = roundf(fnumber * (1 << _fractional_bits)); // doing the same multiplying by 2^8 but cant do it moving bits because is a float
}

float Fixed::toFloat(void) const
{
    // return ((float)_fixed); // with this numbers are astronomically high
    return (static_cast<float>(_fixed) / (1 << _fractional_bits)); // // divide the number by 256 to get the real float also static cast better
}

int Fixed::toInt(void) const
{
    // return ((int)_fixed); // with this numbers are astronomically high
    return (_fixed >> _fractional_bits); //move the number 8 bits to the right again to get the real number
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

std::ostream &operator<<(std::ostream &os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}