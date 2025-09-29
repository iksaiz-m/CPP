#include "Scalar.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Incorrect number of arguments, put one string" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}