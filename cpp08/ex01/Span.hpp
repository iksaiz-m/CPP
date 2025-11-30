#ifndef SPAN_HPP
#define SPAN_HPP

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
#include <cstdlib>
#include <ctime>

class Span
{
private:
    int *elements;
    size_t _size; // size of the array
    size_t _count; // Number of elements already in the array
public:
    Span(unsigned int N); // creates an array of n elements
    Span(const Span &other);
    Span&operator=(const Span &other);
    ~Span();
    size_t size() const;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    void addNumber(int number_to_add);
    int shortestSpan();
    int longestSpan();
    template<typename InputIterator>
    void addRange(InputIterator begin, InputIterator end)
    {
        for (InputIterator it = begin; it != end; ++it)
        {
            if (_count >= _size)
                throw std::runtime_error("No hay espacio para añadir más elementos");
            this->elements[_count] = *it;
            _count++;
        }
    }
};

// template <typename C, typename F>
// void iter(C& container, size_t length, F func)
// {
//     for (size_t i = 0; i < container.size() && i < length; ++i)
//         func(container[i]);
// }




#endif