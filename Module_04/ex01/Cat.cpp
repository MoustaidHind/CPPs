#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Constructor called" << std::endl;
	catBrain = new Brain;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete catBrain;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	catBrain = new Brain();
	*catBrain = *src.catBrain;
	*this = src;
}

Cat& Cat::operator=(const Cat& src)
{
	if(this == &src)
		return(*this);

	Animal::operator=(src);

	delete catBrain;
	this->catBrain = new Brain();
	*this->catBrain = *src.catBrain;

	return(*this);
}

std::string Cat::getType() const
{
	return(type);
}

void Cat::setType(const std::string newType)
{
	this->type = newType;
}

void Cat::makeSound() const
{
	std::cout << "** MEOOOW **" << std::endl;
}
