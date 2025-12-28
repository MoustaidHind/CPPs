#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{

public:
	Dog();
	Dog(const Dog& src);
	Dog& operator=(const Dog& src);
	~Dog();

	std::string getType() const;
	void 		setType(const std::string newType);
	void makeSound() const;

};

#endif