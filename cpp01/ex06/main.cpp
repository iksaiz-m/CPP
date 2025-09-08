#include "Harl.hpp"

int main(int ac, char **av)
{
Harl Harl;
if (ac != 2)
    return (std::cout << "Error: use 2 arguments" << std::endl, 1);
Harl.complain(av[1]);
return (0);
}