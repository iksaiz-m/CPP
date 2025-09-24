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
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
    public:             
        AForm(const std::string name, int signgrade, int execgrade); //default constructor
        AForm(const AForm &other); //copy constructor

        AForm &operator=(const AForm &other); //copy assignment operator
        ~AForm(); // destrcutor
        void beSigned(const Bureaucrat &other);
        const std::string &getName(void) const;
        int getSGrade(void) const;
        int getEGrade(void) const;
        virtual bool issigned(void) const = 0;
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
std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
