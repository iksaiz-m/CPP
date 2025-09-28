#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern Default constructor called" << std::endl;
}

// Intern::Intern(const Intern& other)
// {
//     other
//         std::cout << "Intern Copy constructor called" << std::endl; // doesnt have anything to copy but ok
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
    AForm *newform = NULL; // asigned to null to avoid sending a pointer with something strange if creating fails
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
            std::cout << "Intern creates " << form_name << std::endl;
            newform = new PresidentialPardonForm(target_name);
            break;
        case 1:
            std::cout << "Intern creates " << form_name << std::endl;
            newform = new RobotomyRequestForm(target_name);
            break;
        case 2:
            std::cout << "Intern creates " << form_name << std::endl;
            newform = new ShrubberyCreationForm(target_name);
            break;
        default:
            std::cout << "Intern couldnt create: " << form_name << std::endl;
            break;
        }
    return (newform);
}