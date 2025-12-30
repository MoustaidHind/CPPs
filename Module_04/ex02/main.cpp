#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "AAnimal.hpp"


int main()
{	
	{
		// AAnimal* ptr = new AAnimal; // ERROR MESSSAGE
	}

	{
		Animal *arrAAnimals[4];

		for(int i = 0; i < 4; i++)
		{
			if(i < 2)
				arrAAnimals[i] = new Dog();
			else 
				arrAAnimals[i] = new Cat();
			std::cout << "------------------------------------------------" << std::endl;
		}

		std::cout << "--------------- Aanimal sounds ------------------" << std::endl;
		for(int i = 0; i < 4; i++)
			arrAAnimals[i]->makeSound();

		std::cout << "--------------- destructors --------------------" << std::endl;
	}

	{
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "-             Testing deep copy                -" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;

		Dog* dogA = new Dog();
		dogA->makeSound();

		Dog* dogB = new Dog(*dogA);
		
		std::cout << "---------------------------------------------" << std::endl;
		delete dogA;
		std::cout << "---------------------------------------------" << std::endl;

		dogB->makeSound();

		std::cout << "---------------------------------------------" << std::endl;
		delete dogB;
		std::cout << "---------------------------------------------" << std::endl;
	}

	return 0;
}