#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() 
{
    try
    {
        Bureaucrat pepe;
        // Bureaucrat juan("juan", 1);
        // ShrubberyCreationForm x("Manolo");
        RobotomyRequestForm p("pepe");
        pepe.promotion();
        std::cout << pepe << std::endl;
        // PresidentialPardonForm lame("Paco");
        std::cout << p << std::endl;
        // pepe.signForm(p);
        pepe.executeForm(p);
        p.beSigned(pepe);
        // juan.signForm(p);
        std::cout << p << std::endl;
        // juan.executeForm(p);
        
        // try
        // {
        //     // if Forms function are used, it throws its own execption that needs to be catch if it fails
        //     // lame.beSigned(pepe);
        //     lame.execute(pepe);
        // }
        // catch (const std::exception &e)
        // {
        // std::cerr << "Exception caught: " << e.what() << std::endl;
        // }


        // bureaucrat functions dont need try catch because it catches inside if it fails writting bureaucrat couldnt sign or execute
        // juan.signForm(lame);

        // p.execute(pepe);
        // pepe.signForm(p);
        // pepe.executeForm(p);
        // std::cout << p << std::endl;
        // // AForm deleted("delete", 6, 2);
        // std::cout << lame << std::endl;
        // pepe.signForm(lame);
        // std::cout << lame << std::endl;
        // pepe.executeForm(lame);
        // juan.executeForm(lame);
        // Bureaucrat p;
        // p.promotion();
        // // pepe.promotion();
        // std::cout << p << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}