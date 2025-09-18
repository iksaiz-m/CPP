#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class Bureaucrat
{
    private: 
        const std::string _name;
        int _grade;
    public:             
        Bureaucrat(const std::string name, int grade); //default constructor
        Bureaucrat(const Bureaucrat &other); //copy constructor

        Bureaucrat &operator=(const Bureaucrat &other); //copy assignment operator

        
        ~Bureaucrat(); // destrcutor
        
        void GradeTooHighException();
        void GradeTooLowException();
        void promotion();
        void demotion();
        const std::string &getName(void) const;
        // void setName(std::string& name); // cant use this as it is a const name
        int getGrade() const;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& name);
#endif