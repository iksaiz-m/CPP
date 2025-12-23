#include "BitcoinExchange.hpp"

int textvalues(std::string line, std::string s1, std::string s2)
{
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos = pos + s2.length();
    }
    return (0);
}

int parsefile(std::ifstream &file)
{
    std::string line;
    if (file.is_open())
    {
        if (!std::getline(file, line) || line != "date | value")
        {
            return (std::cerr << "Error: Wrong format in file " << std::endl, 0);
        }
        // while(std::getline(file, line, ' ') && std::getline(file, pipe, ' ') && std::getline(file, value))
        // {
        //     parseline(line, pipe, value);
        // }
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