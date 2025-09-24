#include "Form.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

AForm::AForm(const std::string name, int signgrade, int execgrade) // default constructor
    : _name(name), _sign_grade(signgrade), _exec_grade(execgrade)
{
    if (signgrade < 1 || execgrade < 1)
        throw(AForm::GradeTooHighException());
    if (signgrade > 150 || execgrade > 150)
        throw(AForm::GradeTooLowException());
    std::cout << "AForm Default constructor called" << std::endl;
    this->_signed = false;
}

AForm::AForm(const AForm& other) // copy constructor
    : _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
        std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm has been destroyed" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        // cant do the others because they are a const variable they cant change
        this->_signed = other._signed; 
    }
    std::cout << "AForm Copy assignment operator called" << std::endl;
    return *this;
}

const std::string &AForm::getName(void) const
{
    return (this->_name);
}

int AForm::getSGrade(void) const
{
    return (this->_sign_grade);
}

int AForm::getEGrade(void) const
{
    return (this->_exec_grade);
}

bool AForm::issigned(void) const
{
    return (this->_signed);
}

void  AForm::beSigned(const Bureaucrat &other)
{
    if(other.getGrade() <= this->getSGrade())
    {
        std::cout << other.getName() << " signed " << this->getName() << std::endl;
        this->_signed = true;
    }
    else
        std::cout << other.getName() << " couldn't sign " << this->getName() << " because the grade is too low" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
    os << "AForm " << AForm.getName()
       << " [signed: " << std::boolalpha << AForm.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << AForm.getSGrade()
       << ", grade to execute: " << AForm.getEGrade()
       << "]";
    return os;
}