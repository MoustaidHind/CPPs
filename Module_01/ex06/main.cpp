#include "Harl.hpp"

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
