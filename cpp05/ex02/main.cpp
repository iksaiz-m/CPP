#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() 
{
    try
    {
        Bureaucrat pepe("pepe", 2);
        std::cout << pepe << std::endl;
        // AForm deleted("delete", 6, 2);
        PresidentialPardonForm lame("Paco");
        std::cout << lame << std::endl;
        pepe.signForm(lame);
        std::cout << lame << std::endl;
        // pepe.promotion();
        // std::cout << pepe << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}