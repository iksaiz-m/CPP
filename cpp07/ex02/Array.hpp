#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>

template <typename T>
class Array
{
private:
    T *elements;
public:
    Array<T>(); // creates an empty array
    Array<T>(unsigned int n); // creates an array of n elements
    // Array<T>(Array<T>const &other);
    // Array &operator=(Array<T>const &other);
    ~Array<T>();
    // size_t <T>size();
};

//type <> is needed when using class templates that way compiler know which type of array its creating
template <typename T>
Array<T>::Array(void) : elements(NULL)
{
    std::cout << "An empty array has been created" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    size_t i = 0;
    while(i < n)
    {
        elements[i] = new[T] T();
        std::cout << elements[i] << std::endl;
        i++;
    }
}
// Array<class type>::Array(const Array &other)
// {

// }

// Array<class type>&::operator=(const Array &other)
// {

// }
template <typename T>
Array<T>::~Array()
{
}

// template <typename T>
// size_t Array<T>::size(void)
// {
    
// }

#endif
