#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Animal.hpp"

class Cat : public Animal
{
    private: 
        std::string _type;
    public:             
        Cat(); //default constructor
        Cat(const Cat &other); //copy constructor

        Cat &operator=(const Cat &other); //copy assignment operator

        
        ~Cat(); // destrcutor
        
        void makeSound() const;
        std::string getType() const;
};
#endif