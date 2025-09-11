#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class Fixed  // The class
{
    private: 
        int _fixed;
        static const int _const_fixed = 8;
    public:             
        Fixed(); //default constructor
        Fixed(const Fixed &other); //copy constructor

        Fixed &operator=(const Fixed &other); //copy assignment operator

        
        ~Fixed(); // destrcutor


        int getRawBits(void) const;
        void setRawBits(int const raw);
};
#endif