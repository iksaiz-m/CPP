#ifndef ITER_HPP
#define ITER_HPP

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>


template <typename T, typename F> // typename F allows the use of any kind of function even lambdas defined in the same call.
void iter(T* array, size_t length, F func) // version without constant
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(const T* array, size_t length, F func) // version with constant
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

// function that doesnt modify
template <typename T>
void printElement(const T& elem) 
{
    std::cout << elem;
}

// Funcition that modifies (no const)
template <typename T>
void toUpper(T& c) // passing the element as reference to modify it
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

#endif