#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iomanip>
#include <algorithm>
#include <ctime>
#include <limits>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <fstream>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		std::map<std::string, float> _map;
	public:
		BitcoinExchange(std::string file);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator= (const BitcoinExchange &src);
		~BitcoinExchange();

		void Getvalue(std::ifstream &file);
};
#endif