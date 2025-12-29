#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main()
{	
	Animal* arrAnimals = new Animal[10];

	for(int i = 0; i < 5; i++)
		arrAnimals[i] = Dog();

	for(int i = 0; i < 5; i++)
		arrAnimals[i] = Cat();

	std::cout << "------------- animal sounds ----------------" << std::endl;
	for(int i = 0; i < 10; i++)
		arrAnimals[i].makeSound();

	return 0;
}