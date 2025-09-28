#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :AForm::AForm("RobotomyRequestForm", 72, 45, target)//// default constructor
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    // _target = target;
    // this->_signed = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)//, _target(other._target)// copy constructor
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
    return (*this);
}

void RobotomyRequestForm::executeAction() const
{
    std::srand(std::time(0));          // seed (can be made once in the main)
    int i = std::rand() % 2;           // 0 or 1 random
    std::cout << "PRRRRRRRRRRRRRRRRRRRRR";
    if (i)
        std::cout << " " << this->getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << " the robotomy failed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& RobotomyRequestForm) {
    os << "RobotomyRequestForm " << RobotomyRequestForm.getName()
       << " [signed: " << std::boolalpha << RobotomyRequestForm.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << RobotomyRequestForm.getSGrade()
       << ", grade to execute: " << RobotomyRequestForm.getEGrade()
       << "]";
    return os;
}