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
    return (*this);
}


int typechar(int c)
{
    if ((c <= 90 && c >= 65) || (c <= 122 && c >= 97))
        return (1);
    
    if ((c <= 47 && c >= 32) || (c <= 64 && c >= 58) || (c <= 126 && c >= 123)
        || (c <= 96 && c >= 91))
        return (1);
    return (0);
}
void ScalarConverter::convert(std::string literal)
{
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
        return ;
    }
    if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "+inff" << std::endl;
        std::cout << "double: " << "+inf" << std::endl;
        return ;
    }
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
        return ;
    }
    if (typechar(literal[0]))
    {
        std::cout << "char: " << "'" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
        return ;
    }
    double ii;
	std::stringstream str(literal);
    str >> ii;
    int i = static_cast<int>(ii);
    float f = static_cast<float>(ii);
    if (i >= 32 && i <= 126)
    {
        std::cout << "char: " << "'" <<static_cast<char>(i) << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
    }
    else
    {
        std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
    }
    if (ii == i)
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << ii << ".0" << std::endl;
        }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << ii << std::endl;
    }
    return ;
}