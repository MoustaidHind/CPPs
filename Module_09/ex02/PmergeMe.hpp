#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility> // Required for std::swap
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <deque>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& assign);
	~PmergeMe();

	void sortV(std::vector<int>& arr, int chunk_size);
	void sortD(std::deque<int>& arr, int chunk_size); 
};

#endif