#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Constructor called" << std::endl;
	dogBrain = new Brain;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete dogBrain;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	dogBrain = new Brain();
	*dogBrain = *src.dogBrain;
	*this = src;
}

Dog& Dog::operator=(const Dog& src)
{
	if(this == &src)
		return(*this);

	Animal::operator=(src);
	
	delete dogBrain;
	dogBrain = new Brain();
	*dogBrain = *src.dogBrain;

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
