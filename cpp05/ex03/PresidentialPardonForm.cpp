#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp" // the library here instead of in the hpp to use the functions

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :AForm::AForm("PresidentialPardonForm", 25, 5, target)//, _target(target) // default constructor
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) // copy constructor
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
    return (*this);
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PresidentialPardonForm) {
    os << "PresidentialPardonForm " << PresidentialPardonForm.getName()
       << " [signed: " << std::boolalpha << PresidentialPardonForm.issigned() // boolalpha to make the bool appear as true/false instead of 1/0
       << ", grade to sign: " << PresidentialPardonForm.getSGrade()
       << ", grade to execute: " << PresidentialPardonForm.getEGrade()
       << "]";
    return os;
}