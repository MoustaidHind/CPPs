#include "Animal.hpp"


Animal::Animal() : type("defaultType")
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal Parameterized Constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	this->type = src.getType();
}

Animal& Animal::operator=(const Animal& src)
{
	if(this == &src)
		return(*this);

	this->type = src.getType();

	return(*this);
}

std::string Animal::getType() const
{
	return(type);
}

void Animal::makeSound() const
{
	std::cout << "* Generic animal sound *" << std::endl;
}
