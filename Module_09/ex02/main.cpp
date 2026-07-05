#include "PmergeMe.hpp"


void pritntArr(std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}


void printTime(std::vector<int> &vec, std::deque<int> &deq, double &time_vec, double &time_deq)
{
	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " 
			  << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
			  
	std::cout << "Time to process a range of " << deq.size() 
			  << " elements with std::deque  : " 
			  << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;

}

int main(int ac, char **av)
{
	if(ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe sorter;
	char *endptr;
	std::vector<int> vec;
	std::deque<int> deq;
	struct timespec start_vec, end_vec;
	struct timespec start_deq, end_deq;

	for (int i = 1; i < ac; i++)
	{
		int j = 0;
		while(av[i][j])
		{
			if (j == 0 && av[i][j] == '+' && av[i][j + 1] != '\0') {
				j++;
				continue;
			}
			if(!std::isdigit(av[i][j]))
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
			j++;
		}
		long nb = std::strtol(av[i], &endptr, 10);
		if(*endptr != '\0' || nb < 0 || nb > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		
		vec.push_back(static_cast<int>(nb));
		deq.push_back(static_cast<int>(nb));
	}

	std::cout << "Before: ";
	pritntArr(vec);

	clock_gettime(CLOCK_MONOTONIC, &start_vec);
	sorter.sortV(vec, 1);
	clock_gettime(CLOCK_MONOTONIC, &end_vec);
	double time_vec = (end_vec.tv_sec - start_vec.tv_sec) + (end_vec.tv_nsec - start_vec.tv_nsec) / 1000000000.0;

	clock_gettime(CLOCK_MONOTONIC, &start_deq);
	sorter.sortD(deq, 1);
	clock_gettime(CLOCK_MONOTONIC, &end_deq);		
	double time_deq = (end_deq.tv_sec - start_deq.tv_sec) + (end_deq.tv_nsec - start_deq.tv_nsec) / 1000000000.0;

	std::cout << "After:  ";
	pritntArr(vec);

	printTime(vec, deq, time_vec, time_deq);

	return 0;  
}