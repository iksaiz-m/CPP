#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class Animal  // The class
{
    protected: 
        std::string _type;
    public:             
        Animal(); //default constructor
        Animal(const Animal &other); //copy constructor

        Animal &operator=(const Animal &other); //copy assignment operator

        
        virtual ~Animal(); // Virtual destructor

        virtual void makeSound() const; // virtual because if not it always calls here const because it should not change atributes
        virtual std::string getType() const; // virtual because if not it always calls here const because it should not change atributes
};
#endif