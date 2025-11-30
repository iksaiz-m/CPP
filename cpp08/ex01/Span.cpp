#include "Span.hpp"

Span::Span(unsigned int N) : elements(NULL), _size(N), _count(0)
{
    if (N > 0)
        this->elements = new int[N](); // initialised for every type posible
    std::cout << "An Span of size " << N << " has been created" << std::endl;
}

Span::Span(const Span &other) : elements(NULL), _size(0), _count(0)
{
    size_t len = other.size();
    if (len > 0)
    {
        this->elements = new int[len]; 
        this->_size = len;
        size_t i = 0;
        while (i < len)
        {
            this->elements[i] = other.elements[i];
            _count++;
            i++;
        }
    }
    std::cout << "An Span of size " << len << " has been created using the copy operator" << std::endl;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        delete[] this->elements; // To allocate new memory first we delete the pointer with delete[] 
        this->elements = new int[other.size()];
        this->_size = other.size();
        size_t i = 0;
        _count = 0;
        while (i < _size)
        {
            this->elements[i] = other.elements[i];
            _count++;
            i++;
        }
        std::cout << "An Span of size " << _size << " has been created using the assignment operator" << std::endl;
    }
    return (*this);
}

Span::~Span()
{
    delete[] elements;
    std::cout << "The Span has been destroyed" << std::endl;
}

size_t Span::size(void) const
{
    return (this->_size);
}

int& Span::operator[](size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (this->elements[index]);
}

const int& Span::operator[](size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return (this->elements[index]);
}

void Span::addNumber(int number_to_add)
{
    size_t i = 0;
    if (this->_size == 0)
        throw std::out_of_range("No space available");
    while (i < this->_size)
    {
        if (!this->elements[i])
        {
            this->elements[i] = number_to_add;
            _count++;
            return ;
        }
        i++;
    }
    throw std::out_of_range("No space available");
    return;
}

int Span::longestSpan()
{
    if (this->_size == 0 || this->_size == 1 || !this->elements[1])
    {
        throw std::out_of_range("No Span detected");
        return (0);
    }
    size_t i = 0;
    int result = 0;
    size_t t = 1;
    while (i < t && t < this->_size)
    {
        while (t < this->_size)
        {
            int x = this->elements[i] > this->elements[t] ? this->elements[i] - this->elements[t] : this->elements[t] - this->elements[i];
            result = x > result ? x : result;
            t++;
        }
        i++;
        t = i + 1;
    }
    return (result);
}

int Span::shortestSpan()
{
    if (this->_size == 0 || this->_size == 1 || !this->elements[1])
    {
        throw std::out_of_range("No Span detected");
        return (0);
    }
    size_t i = 0;
    int result = 0;
    size_t t = 1;
    while (i < t && t < this->_size)
    {
        while (t < this->_size)
        {
            int x = this->elements[i] > this->elements[t] ? this->elements[i] - this->elements[t] : this->elements[t] - this->elements[i];
            if (result == 0)
                result = x;
            else
                result = x > result ? result : x;
            t++;
        }
        i++;
        t = i + 1;
    }
    return (result);
}
