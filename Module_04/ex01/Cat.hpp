#pragma once 


#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{
private:
	Brain* catBrain;

public:
	Cat();
	Cat(const Cat& src);
	Cat& operator=(const Cat& src);
	~Cat();

	std::string getType() const;
	void 		setType(const std::string newType);
	void makeSound() const;

};


