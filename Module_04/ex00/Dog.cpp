#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	*this = src;
}

Dog& Dog::operator=(const Dog& src)
{
	if(this == &src)
		return(*this);

	Animal::operator=(src);

	return(*this);
}

std::string Dog::getType() const
{
	return(type);
}

void Dog::setType(const std::string newType)
{
	this->type = newType;
}

void Dog::makeSound() const
{
	std::cout << "** BAARK **" << std::endl;
}
