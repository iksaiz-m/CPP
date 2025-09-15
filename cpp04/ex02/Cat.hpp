#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private: 
        std::string _type;
        Brain *Brain;
    public:             
        Cat(); //default constructor
        Cat(const Cat &other); //copy constructor

        Cat &operator=(const Cat &other); //copy assignment operator

        
        ~Cat(); // destrcutor
        
        void makeSound() const;
        std::string getType() const;
};
#endif