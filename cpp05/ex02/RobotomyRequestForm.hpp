#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>
#include "Form.hpp"
// #include "Bureaucrat.hpp"

class Bureaucrat; //here instead of the library because if not the functions are messed up

class RobotomyRequestForm: public AForm
{
    private: 
    public:             
        RobotomyRequestForm(const std::string &target); //default constructor
        RobotomyRequestForm(const RobotomyRequestForm &other); //copy constructor
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other); //copy assignment operator
        ~RobotomyRequestForm(); // destrcutor
        void executeAction() const; // this one as it is virtual in AForm needs its own take depending on the Form
};
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& AForm);

#endif
