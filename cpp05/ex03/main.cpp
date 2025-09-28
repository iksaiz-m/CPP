#include "Bureaucrat.hpp"
// #include "Form.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() 
{
    //presidential pardon, robotomy request, shrubbery creation
Bureaucrat juan("juan", 1);
Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
if (rrf != NULL)
{
    std::cout << *rrf << std::endl;
    juan.signForm(*rrf);
    juan.executeForm(*rrf);
    delete (rrf);
}
}