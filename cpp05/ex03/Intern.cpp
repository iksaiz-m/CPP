#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
}

// Intern::Intern(const Intern& other)
// {
//     std::cout << "Intern Copy constructor called" << std::endl; // doesnt have anything to copy but ok
// }

Intern& Intern::operator=(const Intern& other) // doesnt do anything either
{
    if (this != &other)
    {
        // this->_grade = other._grade; 
    }
    std::cout << "Intern Copy assignment operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern  has been eliminated" << std::endl;
}

AForm* Intern::makeForm(std::string form_name, const std::string &target_name)
{
    const std::string levels[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *newform;
    int i = 0;
    while (i < 3)
    {
        if (form_name == levels[i]) // compares string with the levels in array
            break ;
        i++;
    }
    switch (i)
        {
        case 0:
            newform = new PresidentialPardonForm(target_name);
            std::cout << "Intern creates " << form_name << std::endl;
            break;
        case 1:
            newform = new RobotomyRequestForm(target_name);
            std::cout << "Intern creates " << form_name << std::endl;
            break;
        case 2:
            newform = new ShrubberyCreationForm(target_name);
            std::cout << "Intern creates " << form_name << std::endl;
            break;
        default:
            std::cout << "Intern couldnt create: " << form_name << std::endl;
            break;
        }
    
    return (newform);
}