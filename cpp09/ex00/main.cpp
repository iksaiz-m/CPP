#include "BitcoinExchange.hpp"



int parsefile(std::ifstream &file)
{
    std::string line;
    if (file.is_open())
    {
        if (!std::getline(file, line) || line != "date | value")
        {
            return (std::cerr << "Error: Wrong format in file " << std::endl, 0);
        }
    }
    else
        return (std::cerr << "Error: could not open file " << std::endl, 0);
    return (1);
}

int main(int ac, char **av)
{
    if(ac !=2)
        return (std::cerr << "Error: could not open file." << std::endl, 1);
    std::ifstream  filename(av[1]);
    if (!parsefile(filename))
    {
        return (1);
    }
    try
    {
        BitcoinExchange bitcoin("data.csv");
        bitcoin.Getvalue(filename);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}