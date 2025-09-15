#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class WrongAnimal  // The class
{
    protected: 
        std::string _type;
    public:             
        WrongAnimal(); //default constructor
        WrongAnimal(const WrongAnimal &other); //copy constructor

        WrongAnimal &operator=(const WrongAnimal &other); //copy assignment operator
        virtual ~WrongAnimal(); // Virtual destructor

        void makeSound() const; // not virtual because that way always calls here const because it should not change atributes
        std::string getType() const; // not virtual because that way always calls here const because it should not change atributes
};
#endif