#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
template <typename T>
class Array
{
private:
    T *elements;
    size_t _size; // size of the array must be actualized every time it changes
public:
    Array<T>(); // creates an empty array
    Array<T>(unsigned int n); // creates an array of n elements
    Array<T>(const Array<T> &other);
    Array<T>&operator=(const Array<T> &other);
    ~Array<T>();
    size_t size() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

//type <> is needed when using class templates that way compiler know which type of array its creating
template <typename T>
Array<T>::Array(void) : elements(NULL), _size(0)
{
    std::cout << "An empty array has been created" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(NULL), _size(n)
{

    if (n > 0)
        this->elements = new T[n];
    std::cout << "An array of size " << n << " has been created" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : elements(NULL), _size(0)
{
    size_t len = other.size();
    if (len > 0)
    {
        this->elements = new T[len]; 
        this->_size = len;
        size_t i = 0;
        while (i < len)
        {
            this->elements[i] = other.elements[i];
            i++;
        }
    }
    std::cout << "An array of size " << len << " has been created using the copy operator" << std::endl;
}

template <typename T>

Array<T>&Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        // if (this->elements) // Checks if there is memory allocated already
        // turns out it doesnt matter if the pointer is null
        delete[] this->elements; // To allocate new memory first we delete the pointer with delete[] 
        this->elements = new T[other.size()];
        this->_size = other.size();
        size_t i = 0;
        while (i < _size)
        {
            this->elements[i] = other.elements[i];
            i++;
        }
        std::cout << "An array of size " << _size << " has been created using the assignment operator" << std::endl;
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
    std::cout << "The Array has been destroyed" << std::endl;
}

template <typename T>
size_t Array<T>::size(void) const
{
    return (this->_size);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (this->elements[index]);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (this->elements[index]);
}


template <typename T>
int& easyfind(T& container, int searched_int);

template <typename T>
int& easyfind(T& container, int searched_int)
{
    for (size_t i = 0; i < container.size(); ++i)
    {
        if (container[i] == searched_int)
            return container[i]; // returns the position using the overloaded [] operator of the container
    }
    throw std::out_of_range("Searched int is not inside of the container");
}

#endif
