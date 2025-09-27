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
        const std::string &_target;
        // bool _signed;
        // const int _sign_grade;
        // const int _exec_grade;
    public:             
        RobotomyRequestForm(const std::string &target); //default constructor
        RobotomyRequestForm(const RobotomyRequestForm &other); //copy constructor

        RobotomyRequestForm &operator=(const RobotomyRequestForm &other); //copy assignment operator
        ~RobotomyRequestForm(); // destrcutor
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
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& AForm);

#endif
