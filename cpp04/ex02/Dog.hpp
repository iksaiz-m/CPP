#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Animal.hpp"

class Dog : public Animal
{
    private: 
        std::string _type;
    public:             
        Dog(); //default constructor
        Dog(const Dog &other); //copy constructor

        Dog &operator=(const Dog &other); //copy assignment operator

        
        ~Dog(); // destrcutor

        void makeSound() const;
        std::string getType() const;
};
#endif