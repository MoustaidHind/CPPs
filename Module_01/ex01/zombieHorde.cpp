#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombies;

	if (N <= 0)
	{
		std::cerr << "Invalid number of zombies !" << std::endl;
		return NULL;
	}

	zombies = new Zombie[N];
	if(!zombies)
	{
		std::cerr << "Memory allocation failed !" << std::endl;
		return NULL;
	}

	for(int i = 0; i < N; i++)
		zombies[i].setname(name);

	return(zombies);
}


