#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	catBrain = new Brain;
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::~Cat()
{
	delete catBrain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	*this = src;
}

Cat& Cat::operator=(const Cat& src)
{
	if(this == &src)
		return(*this);

	Animal::operator=(src);

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
