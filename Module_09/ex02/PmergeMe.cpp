#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {	*this = copy; }

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	(void)src;
	return *this;
}
PmergeMe::~PmergeMe() {}

//  vectore
std::vector<int> Jacobsthal_nbrs(int pend_chunks) // (1, 3, 5, 11...)
{
	std::vector<int> jacob;
	jacob.push_back(1);
	
	if (pend_chunks > 1)
		jacob.push_back(3);

	while (jacob.back() < pend_chunks)
	{
		int next_j = jacob.back() + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next_j);
	}
	return jacob;
}

std::vector<int> reverseIndex(int pend_chunks)  // sort indexs
{
	std::vector<int> idxs;
	std::vector<int> jacob;

	jacob = Jacobsthal_nbrs(pend_chunks); // (1, 3, 5, 11...)
	int last_jacob = 0;

	for (size_t k = 0; k < jacob.size(); k++) 
	{
		int current_jacob = jacob[k];
		if (current_jacob > pend_chunks)
			current_jacob = pend_chunks;
		
		for (int i = current_jacob - 1; i >= last_jacob; i--) {
			idxs.push_back(i);
		}
		last_jacob = current_jacob;
	}
	return idxs;
}


std::vector<int> insertionJaco(std::vector<int>& arr, int chunk_size)
{
	std::vector<int> mainChain;
	std::vector<int> pend;
	std::vector<int> odds;
	std::vector<int> jacobOrder;

	
	mainChain.insert(mainChain.end(), arr.begin(), arr.begin() + chunk_size);
	mainChain.insert(mainChain.end(), arr.begin() + chunk_size, arr.begin() + (2*chunk_size));
	
	size_t i = 2*chunk_size;
	for (; i + (2*chunk_size) <= arr.size(); i += (2*chunk_size)) {
		pend.insert(pend.end(), arr.begin() + i, arr.begin() + i + chunk_size);
		mainChain.insert(mainChain.end(), arr.begin() + i + chunk_size, arr.begin() + i + (2*chunk_size));
	}

	if (arr.size() - i >= (size_t)chunk_size) {
		pend.insert(pend.end(), arr.begin() + i, arr.begin() + i + chunk_size);
		i += chunk_size;
	}

	if (i < arr.size()) {
		odds.insert(odds.end(), arr.begin() + i, arr.end());
	}

	int pend_chunks = pend.size() / chunk_size;
	jacobOrder = reverseIndex(pend_chunks); //(0, 2, 1, 4, 3)
	for (size_t k = 0; k < jacobOrder.size(); k++) 
	{
		int pend_idx = jacobOrder[k];

		std::vector<int>::iterator chunk_start = pend.begin() + (pend_idx * chunk_size);
		std::vector<int>::iterator chunk_end = chunk_start + chunk_size;

		int winnerOfChunk = (*(chunk_start + chunk_size - 1));

		std::vector<int> current_winners;
		for (size_t j = chunk_size - 1; j < mainChain.size(); j += chunk_size) {
			current_winners.push_back(mainChain[j]);
		}

		std::vector<int>::iterator it = std::lower_bound(current_winners.begin(), current_winners.end(), winnerOfChunk);

		int insert_idx = std::distance(current_winners.begin(), it);
		std::vector<int>::iterator insert_pos = mainChain.begin() + (insert_idx * chunk_size);
		mainChain.insert(insert_pos, chunk_start, chunk_end);
	}
	mainChain.insert(mainChain.end(), odds.begin(), odds.end());
	return mainChain;
}


void PmergeMe::sortV(std::vector<int>& arr, int chunk_size) 
{
	if ((arr.size() / chunk_size) < 2) 
		return;

	for (size_t i = 0; i + (2 * chunk_size) <= arr.size(); i += 2*chunk_size)
	{
		if(arr[i + chunk_size - 1] > arr[i + (2 * chunk_size) - 1])
			std::swap_ranges(arr.begin() + i, //start1
							 arr.begin() + i + chunk_size, //end1
							 arr.begin() + i + chunk_size); //start2
	}
	sortV(arr, chunk_size * 2);
	arr =  insertionJaco(arr, chunk_size);
}



//  deque
std::deque<int> insertionJaco(std::deque<int>& arr, int chunk_size)
{
	std::deque<int> mainChain;
	std::deque<int> pend;
	std::deque<int> odds;
	std::vector<int> jacobOrder;

	
	mainChain.insert(mainChain.end(), arr.begin(), arr.begin() + chunk_size); // b1 losser1
	mainChain.insert(mainChain.end(), arr.begin() + chunk_size, arr.begin() + (2*chunk_size)); // a1 winner1
	
	size_t i = 2*chunk_size;
	for (; i + (2*chunk_size) <= arr.size(); i += (2*chunk_size)) {
		pend.insert(pend.end(), arr.begin() + i, arr.begin() + i + chunk_size); // add all losers  b2. b3...
		mainChain.insert(mainChain.end(), arr.begin() + i + chunk_size, arr.begin() + i + (2*chunk_size));
	}

	if (arr.size() - i >= (size_t)chunk_size) {
		pend.insert(pend.end(), arr.begin() + i, arr.begin() + i + chunk_size);
		i += chunk_size;
	}
	if (i < arr.size()) {
		odds.insert(odds.end(), arr.begin() + i, arr.end());
	}

	int pend_chunks = pend.size() / chunk_size;
	jacobOrder = reverseIndex(pend_chunks); //(0, 2, 1, 4, 3)

	for (size_t k = 0; k < jacobOrder.size(); k++) 
	{
		int pend_idx = jacobOrder[k];

		std::deque<int>::iterator chunk_start = pend.begin() + (pend_idx * chunk_size);
		std::deque<int>::iterator chunk_end = chunk_start + chunk_size;

		int winnerOfChunk = (*(chunk_start + chunk_size - 1));

		std::deque<int> current_winners;
		for (size_t j = chunk_size - 1; j < mainChain.size(); j += chunk_size) {
			current_winners.push_back(mainChain[j]);
		}

		std::deque<int>::iterator it = std::lower_bound(current_winners.begin(), current_winners.end(), winnerOfChunk);

		int insert_idx = std::distance(current_winners.begin(), it);
		std::deque<int>::iterator insert_pos = mainChain.begin() + (insert_idx * chunk_size);

		mainChain.insert(insert_pos, chunk_start, chunk_end);
	}
	mainChain.insert(mainChain.end(), odds.begin(), odds.end());
	return mainChain;
}


void PmergeMe::sortD(std::deque<int>& arr, int chunk_size) 
{
	if ((arr.size() / chunk_size) < 2) 
		return;

	for (size_t i = 0; i + (2 * chunk_size) <= arr.size(); i += 2*chunk_size)
	{
		if(arr[i + chunk_size - 1] > arr[i + (2 * chunk_size) - 1])
			std::swap_ranges(arr.begin() + i, //start1
							 arr.begin() + i + chunk_size, //end1
							 arr.begin() + i + chunk_size); //start2
	}
	sortD(arr, chunk_size * 2);
	arr =  insertionJaco(arr, chunk_size);
}
