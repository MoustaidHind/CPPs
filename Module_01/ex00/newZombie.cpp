#include "Zombie.hpp"


Zombie* newZombie(std::string name)
{
	Zombie* z = new Zombie(name);
	if (!z)
	{
		std::cerr << "Memory allocation failed !" << std::endl;
		return NULL;
	}
	return(z);
}