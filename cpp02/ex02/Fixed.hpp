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

        // static is needed because else they need an object to be called a.max(a, b);
        // with static they dont need an object and can be called Fixed::max(a, b);
        //not const functions that takes two references to fixed
        static Fixed &max(Fixed &f1, Fixed &f2);
        static Fixed &min(Fixed &f1, Fixed &f2);

        //const functions that takes two references to constant fixed
        static const Fixed &max(const Fixed &f1, const Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        //comparison operators
        bool operator<(const Fixed &other) const; // removed reference and added const as it shouldnt change any value
        bool operator>(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        //arithmetic operators 
        //not const because we change the value
        // Fixed &operator+(const Fixed &f1, const Fixed &f2); // not like this compiler cries
        Fixed &operator+(const Fixed &other);
        Fixed &operator-(const Fixed &other);
        Fixed &operator*(const Fixed &other);
        Fixed &operator/(const Fixed &other);

        // //increment/decrement operators
        Fixed &operator++(); //preincrement without an int
        Fixed operator++(int x); //post increment with an int
        
        ~Fixed(); // destructor

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        //int ϵ = 0.00390625; //compiler cries:
        //error: non-static data member initializers only available with ‘-std=c++11’ or ‘-std=gnu++11’
    };

std::ostream &operator<<(std::ostream &os, const Fixed& fixed);

#endif