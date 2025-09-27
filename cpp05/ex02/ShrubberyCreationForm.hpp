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
        // const std::string _name;
        // bool _signed;
        // const int _sign_grade;
        // const int _exec_grade;
        const std::string &_target;
    public:             
        ShrubberyCreationForm(const std::string &target); //default constructor
        ShrubberyCreationForm(const ShrubberyCreationForm &other); //copy constructor

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other); //copy assignment operator
        ~ShrubberyCreationForm(); // destrcutor
        void beSigned(const Bureaucrat &other);
        const std::string &getName(void) const;
        int getSGrade(void) const;
        int getEGrade(void) const;
        bool issigned(void) const;
        class GradeTooHighException : public std::exception // exception class without orthodox canonical AForm
        {
            public:
            //     void what();
                const char *what() const throw()
                {
                    return ("Grade is too high");
                }
        };
        class GradeTooLowException : public std::exception // exception class without orthodox canonical AForm
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too low");
                }
        };
};
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& AForm);

#endif
