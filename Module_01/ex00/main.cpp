#include "Zombie.hpp"

int main() 
{

	Zombie* heapZombie = new Zombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // must be deleted manually (heap allocation)

    randomChump("StackZombie"); // auto destroyed when function ends
}


/* 

int *a = malloc(sizeof(int)); free(a):
int *a = new int; delete(a);
	delete just like reset the value inside it , but the a still exist 

*/

/* 
is should exist (2 constructore default, paramtrized)
*/