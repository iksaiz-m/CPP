#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private: 
        std::string _type;
        Brain*  Brain;
    public:             
        Dog(); //default constructor
        Dog(const Dog &other); //copy constructor

        Dog &operator=(const Dog &other); //copy assignment operator

        
        ~Dog(); // destrcutor

        void makeSound() const;
        std::string getType() const;
};
#endif