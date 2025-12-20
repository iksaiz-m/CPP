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

int parsefilename(std::ifstream &file)
{
    std::string line;

    std::getline(file, line);
}


int main(int ac, char **av)
{
    if(ac !=2)
        return(std::cerr << "Error: could not open file." << std::endl, 1);
    std::ifstream  filename(av[1]);
    if (!parsefilename(filename))

    try
    {
        BitcoinExchange bitcoin("data.csv");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }



    if (file_copy.is_open())
    {
        std::string line2;
        while (std::getline(file_copy, line2))
            textvalues(line2, " ");
    }
    else
        return (std::cerr << "Error, couldnt open " << filename << std::endl, 1);
    if ( data.size() == 0 || *data.begin() != "date | value")
        return (std::cerr << "Error " << filename << " should include date and value" << std::endl, 1);
    MutantStack<std::string> data2;
 
    MutantStack<std::string>::iterator it = data.begin();
    MutantStack<std::string>::iterator ite = data.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        it
        ++it;
    }
}