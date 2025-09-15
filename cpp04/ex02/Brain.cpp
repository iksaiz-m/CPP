#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain constructor called" << std::endl;        
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    _ideas[100] = other._ideas[100];
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        _ideas[100] = other._ideas[100];
    }
    std::cout << "Brain Copy assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}