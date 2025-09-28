#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>
#include "Form.hpp"
// #include "Bureaucrat.hpp"

class Bureaucrat; //here instead of the library because if not the functions are messed up

class ShrubberyCreationForm: public AForm
{
    private: 
    public:             
        ShrubberyCreationForm(const std::string &target); //default constructor
        ShrubberyCreationForm(const ShrubberyCreationForm &other); //copy constructor
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other); //copy assignment operator
        ~ShrubberyCreationForm(); // destrcutor
        void executeAction() const; // this one as it is virtual in AForm needs its own take depending on the Form
        // class GradeTooHighException : public std::exception // exception class without orthodox canonical AForm
        // {
        //     public:
        //         const char *what() const throw()
        //         {
        //             return ("Grade is too high");
        //         }
        // };
        // class GradeTooLowException : public std::exception // exception class without orthodox canonical AForm
        // {
        //     public:
        //         const char *what() const throw()
        //         {
        //             return ("Grade is too low");
        //         }
        // };
};
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& AForm);

#endif
