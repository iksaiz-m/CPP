#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class AAnimal  // The class
{
    protected: 
        std::string _type;
    public:             
        AAnimal(); //default constructor
        AAnimal(const AAnimal &other); //copy constructor

        AAnimal &operator=(const AAnimal &other); //copy assignment operator

        
        virtual ~AAnimal(); // Virtual destructor

        virtual void makeSound() const = 0; // making const = 0 makes it purely virtual and because of it not instantiable
        virtual std::string getType() const;
};
#endif