#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility> // Required for std::swap

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <climits>

class PmergeMe
{
private:
	/* data */
public:
	PmergeMe(/* args */);
	~PmergeMe();



	void sortV(std::vector<int>& arr, int chunk_size);
	// void sortD(std::vector<int>& arr, int chunk_size); why not a list 
};


#endif