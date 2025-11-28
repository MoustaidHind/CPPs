#include "Harl.hpp"


// Harl = a made-up person who complains a lot.
// pointers to member functions 
// -> means pointer to the methodes in a specific class 

int main(int ac, char *av[])
{
	Harl h;
	if(ac != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}

	h.complain(std::string(av[1]));
}
