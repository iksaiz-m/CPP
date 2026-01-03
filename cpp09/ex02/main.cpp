#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
        return (std::cerr << "Error: there should be at least be two arguments." << std::endl, 1);
    try
    {
        PmergeMe amigo(av);
        amigo.printlist();
        amigo.sortlist();
        amigo.sortvector();
        amigo.printlist();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
}    