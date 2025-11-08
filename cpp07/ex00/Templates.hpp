#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>

template <typename T>
void swap(T &a, T &b) // pass the arguments as reference else their values arent changed as they will be copies. Return void for no return
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T min(T a, T b)
{
    return (b > a ? a : b); // If b is bigger return a, if is less or equal return b
}

template <typename T>
T max(T a, T b)
{
    return (a > b ? a : b); // if a is bigger return a, if is less or equal return b
}

#endif