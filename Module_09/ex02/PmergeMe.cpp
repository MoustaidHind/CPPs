#include "PmergeMe.hpp"


PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sortV(std::vector<int>& arr, int chunk_size) 
{
	// int chunk_size = 1; //Block Size

    // base case : array mabqatsh kafiya 
    // ==========================================
    if ((arr.size() / chunk_size) < 2) 
	{
        return;
	}

	for (size_t i = 0; i+ (2 * chunk_size) <= arr.size(); i += 2*chunk_size)// 0 1 -> 2 3   -> 4 5 6 7 8 9 10  (i, i+1 )
	{
		if(arr[i + chunk_size - 1] > arr[i + (2 * chunk_size) - 1])
			std::swap_ranges(arr.begin() + i, //start1
							 arr.begin() + i + chunk_size, //end1
							 arr.begin() + i + chunk_size); //start2

		// std::swap(arr[i + chunk_size - 1], arr[i + (2 * chunk_size) - 1]);
	}
	
		std::cout << "ch = " << chunk_size << "--> ";
		for (size_t i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

	sortV(arr, chunk_size * 2);

	// std::cout << "done" << std::endl;
}



