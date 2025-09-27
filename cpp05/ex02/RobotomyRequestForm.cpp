#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) // default constructor
{
    std::cout << " PresidentialPardonForm Default constructor called" << std::endl;
    // _target = target;
    // this->_signed = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)// copy constructor
{
        std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm has been destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        // cant do the others because they are a const variable they cant change
        // this->_signed = other._signed;
        AForm::operator=(other);
    }
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
    return *this;
}

const std::string &RobotomyRequestForm::getName(void) const
{
    // return (this->_name);
    return(AForm::getName());
}

int RobotomyRequestForm::getSGrade(void) const
{
    // return (this->_sign_grade);
    return(AForm::getSGrade());
}

int RobotomyRequestForm::getEGrade(void) const
{
    // return (this->_exec_grade);
    return(AForm::getEGrade());
}

bool RobotomyRequestForm::issigned(void) const
{
    // return (this->_signed);
    return(AForm::issigned());
}

void  RobotomyRequestForm::beSigned(const Bureaucrat &other)
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

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& RobotomyRequestForm) {
    os << "RobotomyRequestForm " << RobotomyRequestForm.getName()
       << " [signed: " << std::boolalpha << RobotomyRequestForm.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << RobotomyRequestForm.getSGrade()
       << ", grade to execute: " << RobotomyRequestForm.getEGrade()
       << "]";
    return os;
}