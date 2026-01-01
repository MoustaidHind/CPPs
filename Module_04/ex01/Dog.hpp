#pragma once 

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
private:
	Brain* dogBrain;
	
public:
	Dog();
	Dog(const Dog& src);
	Dog& operator=(const Dog& src);
	~Dog();

	std::string getType() const;
	void 		setType(const std::string newType);
	void		makeSound() const;

};

