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

// void sortingvector(std::vector<int> losers, std::vector<int> winner, int withoutpair)
 // for (size_t i = 0; i < winner.size(); ++i)
    // {
    //         std::cout << "original winners " << i + 1 << ": (" << winner[i] << ")" << std::endl;
    // }
    // std::cout << std::endl;
    // std::vector<int> winning;
    // for (size_t i = 0; i + 1 < winner.size(); i += 2)
    // {
    //     int a = winner[i];
    //     int b = winner[i + 1];
    //     if (a > b)
    //         std::swap(a, b);
    //     losers.push_back(a);
    //     winning.push_back(b);
    // }
    // if (winner.size() % 2 != 0)
    // {
    //     withoutpair = winner.back();
    //     winning.push_back(withoutpair);
    // }
    // if (winning.size() > 1)
    //     sortingvector(losers, winning, withoutpair);
    // else
    // {
    //     for (size_t i = 0; i < losers.size(); ++i)
    //     {
    //         std::cout << "losers " << i + 1 << ": (" << losers[i] << ")" << std::endl;
    //     }
    //     for (size_t i = 0; i < winning.size(); ++i)
    //     {
    //         std::cout << "last winner " << i + 1 << ": (" << winning[i] << ")" << std::endl;
    //     }
    // }


// void sortingvector(std::vector<int>& losers, std::vector<int>& winners)
void sortingvector(std::vector< std::pair<int,int> >& pairs, std::vector<int>& winners)
{
    // std::vector<int> newWinners;

    // for (size_t i = 0; i + 1 < winners.size(); i += 2)
    // {
    //     int a = winners[i];
    //     int b = winners[i + 1];
    //     if (a > b)
    //         std::swap(a, b);
    //     losers.push_back(a);
    //     newWinners.push_back(b);
    // }
    // if (winners.size() % 2 != 0)
    //     newWinners.push_back(winners.back());

    // winners = newWinners;
    // if (winners.size() == 1)
    // {
    // std::vector<int> result;
    // result.push_back(winners[0]);
    // for (size_t i = 0; i < losers.size(); ++i)
    // {
    //     std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), losers[i]);
    //     result.insert(pos, losers[i]);
    // }
    // winners = result; // ← aquí está el resultado final
    // return;
    // }
    // sortingvector(losers, winners);
    std::vector<int> newWinners;

    for (size_t i = 0; i + 1 < winners.size(); i += 2)
    {
        int a = winners[i];
        int b = winners[i + 1];
        if (a > b)
            std::swap(a, b);
        // guardar la relación
        pairs.push_back(std::make_pair(a, b));
        // solo el winner pasa a la siguiente ronda
        newWinners.push_back(b);
    }

    if (winners.size() % 2 != 0)
        newWinners.push_back(winners.back());

    winners = newWinners;

    if (winners.size() == 1)
    {
        // cadena principal inicial
        std::vector<int> chain;
        chain.push_back(winners[0]);

        // insertar losers (luego aquí irá Jacobsthal)
        // for (i : jacobOrder)
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            int loser  = pairs[i].first;
            int winner = pairs[i].second;

            // el loser solo puede ir antes de su winner
            std::vector<int>::iterator limit =
            std::find(chain.begin(), chain.end(), winner);

            std::vector<int>::iterator pos =
            std::lower_bound(chain.begin(), limit, loser);
            chain.insert(pos, loser);
        }

        winners = chain; // resultado final
        return;
    }
    sortingvector(pairs, winners);
}

// void PmergeMe::sortvector()
// {
//     std::vector< std::pair<int, int> > pairs;
//     std::vector<int> winners;
//     std::vector<int> losers;
//     _withoutpair = -1;
//     for (size_t i = 0; i + 1 < _vector.size(); i += 2)
//     {
//         int a = _vector[i];
//         int b = _vector[i + 1];
//         if (a > b)
//             std::swap(a, b);
//         // pairs.push_back(std::make_pair(a, b));
//         losers.push_back(a);
//         winners.push_back(b);
//     }
//     if (_vector.size() % 2 != 0)
//     {
//         _withoutpair = _vector.back();
//         winners.push_back(_withoutpair);
//     }
//     sortingvector(losers, winners);
// }
void PmergeMe::sortvector()
{
    
    // J(0) = 0
    // J(1) = 1
    // J(n) = J(n−1) + 2·J(n−2)

    // std::vector<size_t> jacob;
    // size_t j1 = 1, j2 = 1;
    // while (j1 < losers.size())
    // {
    //     jacob.push_back(j1);
    //     size_t j3 = j1 + 2 * j2;
    //     j2 = j1;
    //     j1 = j3;
    // }
    // for (size_t idx : jacobOrder)
    // {
    // int value = pairs[idx].loser;
    // int limit = pairs[idx].winner;

    // // buscar SOLO hasta 'limit'
    // std::vector<int>::iterator pos =
    //     std::lower_bound(chain.begin(),
    //                      std::find(chain.begin(), chain.end(), limit),
    //                      value);

    // chain.insert(pos, value);
    // }

    std::vector< std::pair<int,int> > pairs;
    std::vector<int> winners;

    for (size_t i = 0; i + 1 < _vector.size(); i += 2)
    {
        int a = _vector[i];
        int b = _vector[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
        winners.push_back(b);
    }

    if (_vector.size() % 2 != 0)
        winners.push_back(_vector.back());
    sortingvector(pairs, winners);
    // winners ahora está completamente ordenado
    for (size_t i = 0; i < winners.size(); ++i)
    {
        std::cout << "last winner " << i + 1 << ": (" << winners[i] << ")" << std::endl;
    }
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
    // std::cout << pairs();
        // printlist();
}




