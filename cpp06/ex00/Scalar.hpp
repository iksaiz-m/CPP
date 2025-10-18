#ifndef SCALAR_HPP
#define SCALAR_HPP

// #include <cctype>
// #include <string.h>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>

class ScalarConverter
{
    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other); 
    public:
        static void convert(std::string literal);
};
#endif