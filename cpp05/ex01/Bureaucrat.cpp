#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default")
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw(GradeTooHighException());
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) // copy constructor
    : _name(other._name), _grade(other._grade)
{
        std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->_grade = other._grade; 
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    return (*this);
}


void Bureaucrat::promotion(void)
{
    if (Bureaucrat::getGrade() > 1)
        Bureaucrat::_grade -=1;
    else
        throw(GradeTooHighException());
}

void Bureaucrat::demotion()
{
    if (Bureaucrat::getGrade() < 150)
        Bureaucrat::_grade +=1;
    else
        throw(GradeTooLowException());
}

const std::string &Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << getName() << " has been eliminated" << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
    // form.beSigned(*this); // need to change because the exception must be taken here
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& name)
{
    os << name.getName() << ", bureaucrat grade " << name.getGrade();
    return os;
}
