#include <iostream>
#include <cctype>
int main(int ac, char **av)
{
    int i = 1;
    int ii = 0;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (av[i])
        {
            while (av[i][ii])
            {
                std::cout << static_cast<char>(toupper(av[i][ii]));
                ii++;
            }
            ii = 0;
            i++;
            if (av[i])
                std::cout <<" ";
        }
    }
    std::cout << std::endl;
    return (0);
}