#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main()
{	
	{
		// Animal* arrAnimals[10];
		Animal** arrAnimals = new Animal*[4];


		for(int i = 0; i < 4; i++)
		{
			if(i < 2)
				arrAnimals[i] = new Dog();
			else 
				arrAnimals[i] = new Cat();
			std::cout << "------------------------------------------------" << std::endl;
		}


		std::cout << "--------------- animal sounds ------------------" << std::endl;
		for(int i = 0; i < 4; i++)
			arrAnimals[i]->makeSound();

		std::cout << "--------------- destructors --------------------" << std::endl;

		for(int i = 0; i < 4; i++)
		{
			delete arrAnimals[i]; // delete each object 
			std::cout << "------------------------------------------------" << std::endl;
		}

		delete  [] arrAnimals; // delete the array itsefl 
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