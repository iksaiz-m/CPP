#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>

class Bureaucrat
{
    private: 
        const std::string _name;
        int _grade;
    public:             
        Bureaucrat(); //default constructor
        Bureaucrat(const std::string name, int grade); //constructor with parameters
        Bureaucrat(const Bureaucrat &other); //copy constructor

        Bureaucrat &operator=(const Bureaucrat &other); //copy assignment operator

        
        ~Bureaucrat(); // destrcutor
        
        // void GradeTooHighException(); // cant be functions, must be classes already said in the subject ...
        // void GradeTooLowException(); // cant be functions, must be classes already said in the subject ...
        void promotion();
        void demotion();
        const std::string &getName(void) const;
        // void setName(std::string& name); // cant use this as it is a const name
        int getGrade() const;
        class GradeTooHighException : public std::exception // exception class without orthodox canonical form
        {
            public:
            //     void what();
                const char *what() const throw()
                {
                    return ("Grade is too high");
                }
            // GradeTooHighException(const std::string& message) : message_(message) {}
            // const char* what() const throw() { return message_.c_str(); }
        
            // private:
            // std::string message_;
        };
        
        class GradeTooLowException : public std::exception // exception class without orthodox canonical form
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too low");
                }
            //     void what();
            // GradeTooLowException(const std::string& message) : message_(message) {}
            // const char* what() const throw() { return message_.c_str(); }
            
            // private:
            // std::string message_;
        };
};


std::ostream &operator<<(std::ostream &os, const Bureaucrat& name);

#endif
