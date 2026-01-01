#pragma once 

#include "Animal.hpp"


class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& src);
	Cat& operator=(const Cat& src);
	~Cat();

	std::string getType() const;
	void 		setType(const std::string newType);
	void		makeSound() const;

};
