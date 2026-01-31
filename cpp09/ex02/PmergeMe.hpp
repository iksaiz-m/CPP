#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>

#include <sstream>
#include <climits>
#include <stdexcept>
#include <algorithm>

class PmergeMe
{
	private:
	    PmergeMe();
        std::vector<int> _vector;
        std::list<int> _list;
		int _withoutpair;
		size_t jacobstal;

	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator= (const PmergeMe &src);
		~PmergeMe();
		void sortlist();
		void sortvector();
		void printbeforelist();
		void afterlist();
		// void printvector();
		void printvectorpair();
};
template <typename T>
	struct pair
	{
    	T small;
   		T big;
	};

#endif