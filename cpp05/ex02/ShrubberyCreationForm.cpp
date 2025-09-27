#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) // default constructor
{
    std::cout << " ShrubberyCreationForm Default constructor called" << std::endl;
    // _target = target;
    // this->_signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)// copy constructor
{
        std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        // cant do the others because they are a const variable they cant change
        // this->_signed = other._signed;
        AForm::operator=(other);
    }
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
    return *this;
}

const std::string &ShrubberyCreationForm::getName(void) const
{
    // return (this->_name);
    return(AForm::getName());
}

int ShrubberyCreationForm::getSGrade(void) const
{
    // return (this->_sign_grade);
    return(AForm::getSGrade());
}

int ShrubberyCreationForm::getEGrade(void) const
{
    // return (this->_exec_grade);
    return(AForm::getEGrade());
}

bool ShrubberyCreationForm::issigned(void) const
{
    // return (this->_signed);
    return(AForm::issigned());
}

void  ShrubberyCreationForm::beSigned(const Bureaucrat &other)
{
    AForm::beSigned(other);
    // if(other.getGrade() <= this->getSGrade())
    // {
    //     std::cout << other.getName() << " signed " << this->getName() << std::endl;
    //     this->_signed = true;
    // }
    // else
    //     std::cout << other.getName() << " couldn't sign " << this->getName() << " because the grade is too low" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& ShrubberyCreationForm) {
    os << "ShrubberyCreationForm " << ShrubberyCreationForm.getName()
       << " [signed: " << std::boolalpha << ShrubberyCreationForm.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << ShrubberyCreationForm.getSGrade()
       << ", grade to execute: " << ShrubberyCreationForm.getEGrade()
       << "]";
    return os;
}