#ifndef SPAN_HPP
#define SPAN_HPP

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>

class Span
{
private:
    int *elements;
    size_t _size; // size of the array
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
    
};

// template <typename F> // typename F allows the use of any kind of function even lambdas defined in the same call.
//     void iter(int* array, size_t length, F func) // version without constant
//     {
//     for (size_t i = 0; i < length; ++i)
//         func(array[i]);
//     }

template <typename C, typename F>
void iter(C& container, size_t length, F func)
{
    for (size_t i = 0; i < container.size() && i < length; ++i)
        func(container[i]);
}



#endif