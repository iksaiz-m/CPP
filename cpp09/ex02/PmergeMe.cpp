#include "PmergeMe.hpp"

int	handle_repetition(std::vector<int> _vector)
{
    size_t i = 0;
    size_t limit = _vector.size();
    size_t t;
    int n;
    int n2;
    while (i + 1 != limit)
    {
        t = i + 1;
        n = _vector[i];
        n2 = _vector[t];
        while (t != limit)
        {
            n2 = _vector[t];
            if (n == n2)
            {
                return 1;
            }
            t++;
        }
        i++;
    }
    return (0);
}

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
    if (handle_repetition(_vector) == 1)
        throw std::runtime_error("Error: no number repetitions");
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

void PmergeMe::printbeforelist()
{
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std:: endl;
//     Before: 3 5 9 7 4
// After:
// 3 4 5 7 9
// Time to process a range of 5 elements with std::[..] : 0.00031 us
// Time to process a range of 5 elements with std::[..] : 0.00014 us
// std::cout << std::endl;
}

void PmergeMe::afterlist()
{
    std::cout << "After: ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std:: endl;

}

std::vector<size_t> buildJacobOrder(std::size_t pairsize)
{
    std::vector<size_t> jacobstals;
    jacobstals.push_back(1);
    jacobstals.push_back(3);
    while (1)
    {
        size_t next = jacobstals[jacobstals.size()-1] + 2 * jacobstals[jacobstals.size()-2];
        if (next > pairsize)
            break;
        jacobstals.push_back(next);
    }
    return (jacobstals);
}

std::vector<size_t> buildInsertionOrder(size_t pairCount)
{
    std::vector<size_t> order;

    if (pairCount <= 1)
        return order;

    std::vector<size_t> jacob = buildJacobOrder(pairCount);

    size_t prev = 1;

    for (size_t k = 0; k < jacob.size(); ++k)
    {
        size_t j = jacob[k];

        for (size_t i = j; i > prev; --i)
            order.push_back(i - 1); // 🔴 ya 0-based

        prev = j;
    }

    for (size_t i = pairCount; i > prev; --i)
        order.push_back(i - 1);     // 🔴 ya 0-based

    return order;
}

void sortingvector(std::vector<int>& winners)
{
    //crear vectores del nivel
    // std::vector<std::pair<int,int> pairsNivel;
    std::vector< std::pair<int, int> > pairsNivel;
    std::vector<int> newWinners;
    //emparejar
    for (size_t i = 0; i + 1 < winners.size(); i += 2)
    {
        int a = winners[i];
        int b = winners[i + 1];
        if (a > b) 
            std::swap(a, b);
        pairsNivel.push_back(std::make_pair(a, b));
        std::cout << "loser " << a << std::endl;
        newWinners.push_back(b);
    }

    // if (winners.size() % 2 != 0)
    //     newWinners.push_back(winners.back());

    bool hasOdd = (winners.size() % 2 != 0);
    int oddValue = 0;

    if (hasOdd)
        oddValue = winners.back();
        
    if (newWinners.size() > 1)
        sortingvector(newWinners);

    //INSERTAR LOS PEND (al volver)
    std::vector<int> chain = newWinners;
    chain.insert(chain.begin(), pairsNivel[0].first);
    std::vector<size_t> insertOrder = buildInsertionOrder(pairsNivel.size() - 1);

    for (size_t i = 0; i < insertOrder.size(); ++i)
    {
        size_t idx = insertOrder[i] + 1;
        
        int loser  = pairsNivel[idx].first;
        int winner = pairsNivel[idx].second;
        std::cout << "loserjacob" << loser << std::endl;

        std::vector<int>::iterator limit =
            std::find(chain.begin(), chain.end(), winner);

        std::vector<int>::iterator pos =
            std::lower_bound(chain.begin(), limit, loser);

        chain.insert(pos, loser);
    }

    if (hasOdd)
    {
        std::cout << oddValue << std::endl;
                std::cout << "oddValue" << oddValue << std::endl;
        std::vector<int>::iterator pos =
            std::lower_bound(chain.begin(), chain.end(), oddValue);
        chain.insert(pos, oddValue);
    }

    winners = chain;
}

void PmergeMe::sortvector()
{
    sortingvector(_vector);
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
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
}




