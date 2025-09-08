#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>

class Harl  // The class
{
    private: // Access specifier
        // std::string _level;
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:             // Access specifier
        Harl();
        ~Harl();
        void complain(std::string level);
};
#endif