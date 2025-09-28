#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
    private: 
        const std::string _name;
        int _grade;
    public:             
        Bureaucrat(); //default constructor
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other); //copy constructor

        Bureaucrat &operator=(const Bureaucrat &other); //copy assignment operator

        ~Bureaucrat(); // destrcutor

        void promotion();
        void demotion();
        const std::string &getName(void) const;
        int getGrade() const;
        void signForm(AForm &form);
        void executeForm(AForm const & form) const;
        class GradeTooHighException : public std::exception // exception class without orthodox canonical form
        {
            public:
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat& name);

#endif
