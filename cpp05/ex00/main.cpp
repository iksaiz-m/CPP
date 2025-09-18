#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat pepe("pepe", 2);
        std::cout << pepe << std::endl;
        pepe.promotion();
        std::cout << pepe << std::endl;
        pepe.promotion();
        std::cout << pepe << std::endl;
        Bureaucrat manolo("manolo", 151);
        std::cout << manolo << std::endl;
        manolo.promotion();
        std::cout << manolo << std::endl;
        manolo.promotion();
        std::cout << manolo << std::endl;
    }
    catch(int gradeerror)
       {
           Bureaucrat::GradeTooHighException();
           // std::cerr << e.what() << '\n';
       }
}