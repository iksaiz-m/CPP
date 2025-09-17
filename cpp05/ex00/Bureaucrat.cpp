#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
    if (grade < 1)
        Bureaucrat::GradeTooHighException();
        
    else if (grade > 1)
        GradeTooLowException();
    else
        setName(name);
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        setName(other._name);
        _grade = other.getGrade();
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

void Bureaucrat::setName(const std::string& name)
{
    _name = name;
}

// void Bureaucrat::setName(const std::string& name)
// {
//     _name = name;
// }
int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}



Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << getName() << " has been eliminated" << std::endl;
}

void Bureaucrat::GradeTooHighException()
{
    std::cout << "Grade is too high" << std::endl;
    Bureaucrat::~Bureaucrat();

}

void Bureaucrat::GradeTooLowException()
{
    std::cout << "Grade is too low" << std::endl;
    Bureaucrat::~Bureaucrat();
}
