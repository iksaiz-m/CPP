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
        throw ("Error couldnt open ", file, " filename");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _map(copy._map) {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
			this->_map = src._map;
		return (*this);
}

BitcoinExchange::~BitcoinExchange(){}



