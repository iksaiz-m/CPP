#include "Bureaucrat.hpp"

// int main() //bureaucrat promoted too much!
// {
//     try
//     {
//         Bureaucrat pepe("pepe", 2);
//         std::cout << pepe << std::endl;
//         pepe.promotion();
//         std::cout << pepe << std::endl;
//         pepe.promotion();
//         std::cout << pepe << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }
// }

// int main() //bureaucrat copied by constructor and promoted too much!
// {
//     try
//     {
//         Bureaucrat pepe("pepe", 2);
//         std::cout << pepe << std::endl;
//         pepe.promotion();
//         std::cout << pepe << std::endl;
//         Bureaucrat manolo(pepe);
//         std::cout << manolo << std::endl;
//         manolo.promotion();
//         // pepe.promotion();
//         // std::cout << pepe << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }
// }

int main() //bureaucrat copy operator and promoted too much!
{
    try
    {
        Bureaucrat pepe("pepe", 2);
        std::cout << pepe << std::endl;
        pepe.promotion();
        std::cout << pepe << std::endl;
        Bureaucrat manolo("manolo", 100);
        std::cout << manolo << std::endl;
        manolo = pepe;
        std::cout << manolo << std::endl;
        manolo.promotion();
        // pepe.promotion();
        // std::cout << pepe << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

// int main(void) //bureaucrat created too high!
// {
//     try
//     {
//         Bureaucrat iker("iker", -10);
//         std::cout << iker << std::endl;
//         for (int i = 0; i < 20; i++)
//         {
//             iker.promotion();
//             std::cout << iker << std::endl;
//         }
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return (0);
// }

// int main(void) //bureaucrat created grade too low!
// {
//     try
//     {
//         Bureaucrat iker("iker", 155);
//         std::cout << iker << std::endl;
//         for (int i = 0; i < 20; i++)
//         {
//             iker.promotion();
//             std::cout << iker << std::endl;
//         }
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return (0);
// }

// int main(void) //bureaucrat demoted too much!
// {
//     try
//     {
//         Bureaucrat iker("iker", 149);
//         std::cout << iker << std::endl;
//         iker.demotion();
//         std::cout << iker << std::endl;
//         iker.demotion();
//         std::cout << iker << std::endl;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }

//     return (0);
// }