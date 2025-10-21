#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

// #include <cctype>
// #include <string.h>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdint.h> //  needed to read uintptr_t

typedef struct Data
{
	std::string	content;
	int		    i;
}				Data;

class Serializer
{
    private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other); 
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
#endif