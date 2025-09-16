#include "Fixed.hpp"

Fixed::Fixed() 
{
    std::cout << "Default constructor called" << std::endl;
    _fixed = 0 << _fractional_bits;
}

Fixed::Fixed(int number)
{
    std::cout << "Int constructor called" << std::endl;
     _fixed = number << _fractional_bits;
}

Fixed::Fixed(const float fnumber)
{
    std::cout << "Float constructor called" << std::endl;
    _fixed = roundf(fnumber * (1 << _fractional_bits));
}

float Fixed::toFloat(void) const
{
    // return ((float)_fixed); // with this numbers are astronomically high
    return ((_fixed) / (1 << _fractional_bits)); // divide the number by 256 to get the real float
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

// bool &Fixed::operator<(const Fixed &other) // cant be done like this because the returned bool is not an lvalue and cant have a reference
// {
//     std::cout << "less than operator called" << std::endl;
//     if (this != &other)
//     {
//         if (_fixed < other._fixed)
//             return (_fixed < other._fixed);
//         else
//             return (false);
//         // _fixed = other._fixed;
//     }
//     return (false);
// }

bool Fixed::operator<(const Fixed &other) const
{
    return (_fixed < other._fixed);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (_fixed > other._fixed);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (_fixed >= other._fixed);
}
bool Fixed::operator<=(const Fixed &other) const
{
    return (_fixed <= other._fixed);
}
bool Fixed::operator==(const Fixed &other) const
{
    return (_fixed == other._fixed);
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (_fixed != other._fixed);
}

// Fixed &Fixed::operator+(const Fixed &f1, const Fixed &f2)
// {

// }
Fixed &Fixed::operator+(const Fixed &other)
{
    _fixed = _fixed + other._fixed;
    return (*this);
}

Fixed &Fixed::operator-(const Fixed &other)
{
    _fixed = _fixed - other._fixed;
    return (*this);
}

Fixed &Fixed::operator*(const Fixed &other)
{
    _fixed = _fixed * other._fixed;
    return (*this);
}

Fixed &Fixed::operator/(const Fixed &other)
{
    _fixed = _fixed / other._fixed;
    return (*this);
}

Fixed &Fixed::operator++()
{
    _fixed += (1 << _fractional_bits); // add before returning
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _fixed += (1 << _fractional_bits); // added but returning previous value
    return (tmp);
}

// Fixed &Fixed::operator+(const Fixed &other)
// {
//     if (this != &other)
//     {
//         _fixed = other._fixed;
//     }
//     std::cout << "Copy assignment operator called" << std::endl;
//     return (*this);
// }



Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    std::cout << "max assignment operator called" << std::endl;
    if (f1 > f2)
    {
        return(f1);
    }
    return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    std::cout << "min assignment operator called" << std::endl;
    if (f1 > f2)
    {
        return(f2);
    }
    return (f1);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    std::cout << "max assignment operator called" << std::endl;
    if (f1 > f2)
    {
        return(f1);
    }
    return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    std::cout << "min assignment operator called" << std::endl;
    if (f1 > f2)
    {
        return(f2);
    }
    return (f1);
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