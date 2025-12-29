#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>

class PmergeMe
{
	private:
        std::vector<int> _vector;
        std::list<int> _list;
	public:
        // PmergeMe();
        PmergeMe() {};
		// PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator= (const PmergeMe &src);
		~PmergeMe();
        
};

#endif