#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <cmath>

class Fixed  // The class
{
    private: 
        int _fixed;
        static const int _fractional_bits = 8;
    public:             
        Fixed(); //default constructor
        Fixed(int number); //constructor with int parameter
        Fixed(const float fnumber); //constructor with float parameter 
        Fixed(const Fixed &other); //copy constructor

        Fixed &operator=(const Fixed &other); //copy assignment operator

        
        ~Fixed(); // destrcutor

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};
#endif