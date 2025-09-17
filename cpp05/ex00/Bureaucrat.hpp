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
        
        void makeSound() const;
        std::string getType() const;
        void GradeTooHighException();
        void GradeTooLowException();
        std::string getName(void) const;
        void setName(const std::string& name);
        int getGrade() const;

};
#endif