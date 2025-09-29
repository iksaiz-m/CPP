#include "Scalar.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Scalar has been destroyed";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {*this = other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
     if (this != &other)
     {

     }
    // std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
    return (*this);
}

int chartoint(int c)
{
    if (c >= 0 && c <= 0177)
        return (c);
    return (c);
}

int typechar(int c)
{
    if ((c < 90 && c > 65) || (c < 122 && c > 97))
        return (1);
    return (0);
}
void ScalarConverter::convert(std::string literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return ;
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return ;
    if (typechar(literal[0]))
        std::cout << "good char" << std::endl;
    std::cout << "char: " << literal[0] << std::endl;
    
    std::cout << "int: " << static_cast<char>(chartoint(literal[0])) << std::endl;
    // isascii(literal);
    // static_cast<float>
    // std::cout << "int: " << std::atoi(literal.c_str()) << std::endl;
    // std::atoi("a");
    // std::cout << literal << std::endl;
    // char: Non displayable
    // int: 0
    // float: 0.0f
    // double: 0.0
}
