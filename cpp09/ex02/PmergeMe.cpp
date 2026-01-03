#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        std::stringstream ss(av[i]);
        long long number;
        char character;
        if (!(ss >> number))
            throw std::runtime_error("Error: Not a number");
        if (ss >> character)
            throw std::runtime_error("Error: Not a number");
        if (number < 0)
            throw std::runtime_error("Error: only positive numbers are allowed");
        if (number > INT_MAX)
            throw std::runtime_error("Error: number too large");
        _vector.push_back(static_cast<int>(number));
        _list.push_back(static_cast<int>(number));
    }
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _vector(copy._vector), _list(copy._list) {}

PmergeMe & PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        this->_vector = src._vector;
        this->_list = src._list;
    }
		return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::printlist()
{
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
{
    std::cout << *it << " ";
}
std::cout << std::endl;
}


void PmergeMe::printvector()
{
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
{
    std::cout << *it << " ";
}
std::cout << std::endl;
}

void PmergeMe::sortvector()
{
    std::vector< std::pair<int, int> > pairs;
    _withoutpair = -1;
    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        int a = _vector[i];
        int b = _vector[i + 1];
        if (a < b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (_vector.size() % 2 != 0)
        _withoutpair = _vector.back();

}
void PmergeMe::sortlist()
{
    std::list< std::pair<int, int> > pairs;
    _withoutpair = -1;
    
    std::list<int>::iterator it = _list.begin();
    
    while (it != _list.end())
    {
        int first = *it;
        ++it;
    
        if (it == _list.end())
        {
            _withoutpair = first;
            break;
        }
    
        int second = *it;
        ++it;
    
        if (first < second)
            std::swap(first, second);
    
        pairs.push_back(std::make_pair(first, second));
    }
}

