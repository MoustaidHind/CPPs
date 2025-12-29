#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("defaultType")
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal Parameterized Constructor called" << std::endl;
}


WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	this->type = src.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	if(this == &src)
		return(*this);

	this->type = src.getType();

	return(*this);
}

std::string WrongAnimal::getType() const
{
	return(type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "* Generic WrongAnimal sound *" << std::endl;
}
