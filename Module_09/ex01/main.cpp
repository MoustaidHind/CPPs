#include "RPN.hpp"


int main(int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr << "Error\n" << std::endl;
		return 1;
	}

	RPN opera1;
	opera1.calculation(av[1]);
	
}