#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "Foo";

    Zombie* horde = zombieHorde(N, name);

    for (int i = 0; i < N; i++)
    {
        std::cout << "Zombie " << i + 1 << " ";
        horde[i].announce();
    }

	delete[] horde;
}



/* 

- new[] / delete[]	: Allocate and free arrays of objects ~~~
- Default constructor	: Required when creating an array of objects
- Setters	: To assign names after construction
- Loops with object arrays	: To initialize and call methods for each Zombie
- Memory management (valgrind)	: To verify no leaks occur


-> how delete know how many block allocated in array , cuz secretly the new[] store how many object created to use it when we call the delete[] operation
*/

