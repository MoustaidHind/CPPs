#include "Zombie.hpp"

int main() 
{
	Zombie* heapZombie = newZombie("HeapZombie");
	if (!heapZombie)
		return 1;	
    heapZombie->announce();
    delete heapZombie;

    randomChump("StackZombie");
}

