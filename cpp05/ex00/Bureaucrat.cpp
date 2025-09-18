#include "Bureaucrat.hpp"

// Bureaucrat::Bureaucrat(std::string name, int grade)
// {
    // if (grade < 1)
    //     Bureaucrat::GradeTooHighException();
        
    // else if (grade > 1)
    //     GradeTooLowException();
//     else
//         // setName(name);
//     Bureaucrat::_name = name;
// }

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade) //constructed the bureaucrat with the name and grade
{
    // try
    // {
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException);
    // }
    // catch(int gradeerror)
    // {
    //     Bureaucrat::GradeTooHighException(); //removing catch from here to avoid creating the object even if it is invalid
    //     // std::cerr << e.what() << '\n';
    // }
    // try
    // {
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    // }
    // }
    // catch(int gradeerror2)
    // {
    //     Bureaucrat::GradeTooLowException();
    // }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        // _name = other._name; // cant do this because it is a const variable it cant change
        _grade = other._grade; 
    }
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    return *this;
}


void Bureaucrat::promotion(void)
{
    try
    {
        if (Bureaucrat::getGrade() > 1)
            Bureaucrat::_grade -=1;
    
        // if (Bureaucrat::getGrade() < 1)
        if (Bureaucrat::getGrade() == 1)
            throw(Bureaucrat::GradeTooHighException);
        else
            throw(Bureaucrat::GradeTooHighException());
            // throw(Bureaucrat::getGrade());
    }
    // catch(int gradeerror)
    // {
    //     Bureaucrat::GradeTooHighException();
    //     // std::cerr << e.what() << '\n';
    // }
}

void Bureaucrat::demotion()
{
    try
    {
        if (Bureaucrat::getGrade() < 150)
            Bureaucrat::_grade +=1;
        // Bureaucrat::_grade +=1;
        // if (Bureaucrat::getGrade() > 150)
        else
        throw(Bureaucrat::GradeTooLowException());
            // throw(Bureaucrat::getGrade());
    }
    // catch(int gradeerror2)
    // {
    //     Bureaucrat::GradeTooLowException();
    // }
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

void Bureaucrat::GradeTooHighException()
{
    std::cout << getName() << " Grade is too high" << std::endl;
    // Bureaucrat::~Bureaucrat();

}

void Bureaucrat::GradeTooLowException()
{
    std::cout << getName() << " Grade is too low" << std::endl;
    // Bureaucrat::~Bureaucrat();
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat& name)
{
    os << name.getName() << " grade " << name.getGrade();
    return os;
}
