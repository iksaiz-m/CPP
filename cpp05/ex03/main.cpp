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
Bureaucrat jaime("jaime", 150);
Intern someRandomIntern;
Intern p; 
p = someRandomIntern;
AForm* rrf;
rrf = p.makeForm("robotomy request", "Bender");
if (rrf != NULL)
{
    std::cout << *rrf << std::endl;
    juan.signForm(*rrf);
    jaime.executeForm(*rrf);
    juan.executeForm(*rrf);
    delete (rrf);
}
}