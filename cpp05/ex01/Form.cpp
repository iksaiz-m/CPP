#include "Form.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

Form::Form(const std::string name, int signgrade, int execgrade) // default constructor
    : _name(name), _sign_grade(signgrade), _exec_grade(execgrade)
{
    if (signgrade < 1 || execgrade < 1)
        throw(Form::GradeTooHighException());
    if (signgrade > 150 || execgrade > 150)
        throw(Form::GradeTooLowException());
    std::cout << "Form Default constructor called" << std::endl;
    this->_signed = false;
}

Form::Form(const Form& other) // copy constructor
    : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
        std::cout << "Form Copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form has been destroyed" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // cant do the others because they are a const variable they cant change
        this->_signed = other._signed; 
    }
    std::cout << "Form Copy assignment operator called" << std::endl;
    return *this;
}

const std::string &Form::getName(void) const
{
    return (this->_name);
}

int Form::getSGrade(void) const
{
    return (this->_sign_grade);
}

int Form::getEGrade(void) const
{
    return (this->_exec_grade);
}

bool Form::issigned(void) const
{
    return (this->_signed);
}

void  Form::beSigned(const Bureaucrat &other)
{
    if(other.getGrade() <= this->getSGrade())
    {
        std::cout << other.getName() << " signed " << this->getName() << std::endl;
        this->_signed = true;
    }
    else
        std::cout << other.getName() << " couldn't sign " << this->getName() << " because the grade is too low" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName()
       << " [signed: " << std::boolalpha << form.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << form.getSGrade()
       << ", grade to execute: " << form.getEGrade()
       << "]";
    return os;
}