#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private: 
        std::string _type;
    public:             
        WrongCat(); //default constructor
        WrongCat(const WrongCat &other); //copy constructor

        WrongCat &operator=(const WrongCat &other); //copy assignment operator

        
        virtual ~WrongCat(); // Virtual destructor

        void makeSound() const; // const because it should not change atributes
        std::string getType() const; // const because it should not change atributes
};
#endif