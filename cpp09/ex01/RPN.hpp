#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef std::stack<T> stack;
    typedef typename stack::container_type container;
    typedef typename container::iterator iterator;

    MutantStack() : stack()
    {
        std::cout << "Default Constructor called" << std::endl;
    }

    MutantStack(const stack &other) : stack(other)
    {
        std::cout << "Copy Constructor called" << std::endl;
    }

    stack &operator=(const stack &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}

    ~MutantStack()
    {
        std::cout << "MutantStack has been destroyed" << std::endl;
    }
    
    iterator begin()
    {
        return (this->c.begin());
    }
    iterator end()
    {
        return (this->c.end());
    }
};

    

#endif