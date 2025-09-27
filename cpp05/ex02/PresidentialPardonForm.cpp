#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) // default constructor
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    // _target = target;
    // this->_signed = false;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target)// copy constructor
{
        std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm has been destroyed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        // cant do the others because they are a const variable they cant change
        // this->_signed = other._signed;
        AForm::operator=(other);
    }
    std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
    return *this;
}

const std::string &PresidentialPardonForm::getName(void) const
{
    // return (this->_name);
    return(AForm::getName());
}

int PresidentialPardonForm::getSGrade(void) const
{
    // return (this->_sign_grade);
    return(AForm::getSGrade());
}

int PresidentialPardonForm::getEGrade(void) const
{
    // return (this->_exec_grade);
    return(AForm::getEGrade());
}

bool PresidentialPardonForm::issigned(void) const
{
    // return (this->_signed);
    return(AForm::issigned());
}

void  PresidentialPardonForm::beSigned(const Bureaucrat &other)
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

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PresidentialPardonForm) {
    os << "PresidentialPardonForm " << PresidentialPardonForm.getName()
       << " [signed: " << std::boolalpha << PresidentialPardonForm.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << PresidentialPardonForm.getSGrade()
       << ", grade to execute: " << PresidentialPardonForm.getEGrade()
       << "]";
    return os;
}