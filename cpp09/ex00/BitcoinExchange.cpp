#include "BitcoinExchange.hpp"

// int parsedate(std::string date, std::string value)
// {
//     if (atol(value))
// }


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string file)
{
    std::ifstream infile(file.c_str());
    if (!infile)
        throw ("Error, there should be a data.csv filename");
    std::string date;
	std::string value;
    if (infile.is_open())
    {
        std::getline(infile, value);
        while(std::getline(infile, date, ',') && std::getline(infile, value))
        {
            _map.insert(std::make_pair(date, std::strtof(value.c_str(), NULL)));
        }

    }
    else
        throw ("Error couldnt open file");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _map(copy._map) {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
			this->_map = src._map;
		return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

int parseline(const std::string& date, const std::string& value)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (std::cout << "Wrong date format" << std::endl, 0);
    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());
    if (year < 2009 || year > 2022)
        return (std::cout << "Wrong date" << std::endl, 0);
    if (month < 1 || month > 12)
        return (std::cout << "Wrong date format" << std::endl, 0);
    if (day < 1 || day > 31)
        return (std::cout << "Wrong date format" << std::endl, 0);

    char* end;
    float v = std::strtof(value.c_str(), &end); // this makes sure that the value is either int or float
    if (*end != '\0')
        return (std::cout << "Wrong value format" << std::endl, 0);
    if (end == value.c_str())
        return (std::cout << "Error: no value detected." << std::endl, 0);
    if (v < 0)
        return (std::cout << "Error: not a positive number." << std::endl, 0);
    if (v > 1000)
        return (std::cout << "Error: too large a number." << std::endl, 0);
    return 1;
}

void BitcoinExchange::Getvalue(std::ifstream &file)
{
    std::string line;
    while(std::getline(file, line))
    {
        if (line.empty())
            continue; // the program doesnt end
        size_t pos = line.find('|');
        if (pos == std::string::npos) // check if there is no pipe in line
        {
            std::cout << "Error: wrong pipe format." << std::endl;
            continue; // the program doesnt end
        }
        std::string date = line.substr(0, pos - 1); // start to pipe
        std::string value = line.substr(pos + 2); // from pipe + 2
        if (parseline(date, value))
        {
            std::map<std::string, float>::iterator it = _map.lower_bound(date);
            if (it == _map.begin())
                std::cout << "No earlier date available" << std::endl;
            else
            {
                if (it == _map.end() || it->first != date)
                    --it;

                std::cout << date << " => " << value << " = " << std::atof(value.c_str()) *it->second << std::endl;
            }
        }
    }
}
