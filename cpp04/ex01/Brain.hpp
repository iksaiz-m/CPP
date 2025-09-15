#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include "Animal.hpp"

class Brain
{
    private: 
        std::string _ideas[100];
    public:
        Brain(); //default constructor
        Brain(const Brain &other); //copy constructor

        Brain &operator=(const Brain &other); //copy assignment operator
        ~Brain(); // destrcutor
};
#endif