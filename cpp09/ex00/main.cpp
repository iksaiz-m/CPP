#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac !=2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    std::string filename = (av[1]);
    if (filename.empty())
        return (std::cout << "Error, there should be a filename" << std::endl, 1);
    if (!"/data.csv")
    {
        std::cout << "Error: file data.csv" << std::endl;
        return (1);
    }
    MutantStack<char> data;
    // data.
    MutantStack<char>::

    std::ifstream file_copy(filename.c_str());
    if (file_copy.is_open())
    {
        std::string line;
        while (std::getline(file_copy, line))
        {
            if (line.)
        }
    }

}