#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>
// #include "Bureaucrat.hpp"

class Bureaucrat; //here instead of the library because if not the functions are messed up

class Form
{
    private: 
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
    public:             
        Form(const std::string name, int signgrade, int execgrade); //default constructor
        Form(const Form &other); //copy constructor

        Form &operator=(const Form &other); //copy assignment operator
        ~Form(); // destrcutor
        void beSigned(const Bureaucrat &other);
        const std::string &getName(void) const;
        int getSGrade(void) const;
        int getEGrade(void) const;
        bool issigned(void) const;
        class GradeTooHighException : public std::exception // exception class without orthodox canonical form
        {
            public:
            //     void what();
                const char *what() const throw()
                {
                    return ("Grade is too high");
                }
        };
        class GradeTooLowException : public std::exception // exception class without orthodox canonical form
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too low");
                }
        };
};
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
