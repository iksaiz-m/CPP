#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

#include <cstdlib>
#include <map>
#include <fstream>
#include <ctime>
#include <limits>
#include <string>

#include <iostream>
#include <sstream>		//
#include <cstdlib>		//std::strtof()
#include <map>			//std::map
#include <fstream>		//std::ifstream

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

    // iterator begin()
    // {
    //     return (this->c.begin());
    // }
    // iterator end()
    // {
    //     return (this->c.end());
    // }
    

#endif