#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    try
    {
        Bureaucrat pepe("pepe", 2);
        std::cout << pepe << std::endl;
        Form deleted("delete", 6, 2);
        std::cout << deleted << std::endl;
        pepe.signForm(deleted);
        std::cout << deleted << std::endl;
        // pepe.promotion();
        // std::cout << pepe << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}