#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern //: public PresidentialPardonForm, public RobotomyRequestForm, public ShrubberyCreationForm
{
    private: 

    public:             
        Intern(); //default constructor
        // Intern(const std::string name, int grade); cant be made has not atributes
        // Intern(const Intern &other); //copy constructor but does nothing compiler cries with other being unused

        Intern &operator=(const Intern &other); //copy assignment operator but does nothing

        ~Intern(); // destrcutor
        AForm *makeForm(std::string form_name, const std::string &target_name);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& name);

#endif
