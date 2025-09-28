#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <cctype>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
// #include "Bureaucrat.hpp"

class Bureaucrat; //here instead of the library because if not the functions are messed up

class AForm
{
    private: 
        const std::string _name;
        bool _signed;
        const int _sign_grade;
        const int _exec_grade;
        const std::string _target;
    public:             
        AForm(); // true default constructor but will not happen because it is uninstantiable
        AForm(const std::string name, int signgrade, int execgrade, const std::string target); //default constructor
        AForm(const AForm &other); //copy constructor

        AForm &operator=(const AForm &other); //copy assignment operator
        virtual ~AForm(); // virtual destrcutor
        void beSigned(const Bureaucrat &other);
        const std::string &getName(void) const;
        int getSGrade(void) const;
        int getEGrade(void) const;
        const std::string &getTarget(void) const;
        bool issigned(void) const;
        virtual void executeAction(void) const = 0; // purely virtual function to make it abstract and to avoid being called from here
        void execute(Bureaucrat const & executor) const;
        
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
        class CouldntexecuteException : public std::exception // exception class without orthodox canonical AForm
        {
            public:
                const char *what() const throw()
                {
                    return ("Form is either not signed or grade is too low");
                }
        };
};
std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
