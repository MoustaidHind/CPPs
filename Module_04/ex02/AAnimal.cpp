#include "AAnimal.hpp"


AAnimal::AAnimal() : type("defaultType")
{
	std::cout << "AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal Parameterized Constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	this->type = src.getType();
}

AAnimal& AAnimal::operator=(const AAnimal& src)
{
	if(this == &src)
		return(*this);

	this->type = src.getType();

	return(*this);
}

std::string AAnimal::getType() const
{
	return(type);
}

