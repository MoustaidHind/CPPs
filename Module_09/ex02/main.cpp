#include "PmergeMe.hpp"


// Merge-Insert Sort (awla Ford-Johnson Algorithm

int main(int ac, char **av)
{

	std::vector<int> arr;

	if(ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	// store input 
	char	*endptr;
	for (int i = 1; i < ac; i++)
	{
		int j = 0;
		while(av[i][j])
		{
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
		arr.push_back(static_cast<int>(nb));
	}

	std::cout << "Before : ";
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	PmergeMe sorter;
	sorter.sortV(arr, 1);

	std::cout << "After : ";
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
	
}

/*
Khassk t-fhem l-farq f l-memory bin std::vector (memory block wahed m-tassel) u std::deque
(chunks d memory m-qesmin) aw std::list (nodes), u 3lach l-weqt d l-sorting kiy-koun mkhtalef 
binathom. L-subject kiy-ns7k t-kteb l-algorithm l-kul container b-tariqa m-fessla
(avoid generic functions)
*/