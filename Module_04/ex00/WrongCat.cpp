#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	*this = src;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	if(this == &src)
		return(*this);

	WrongAnimal::operator=(src);

	return(*this);
}

std::string WrongCat::getType() const
{
	return(type);
}

void WrongCat::setType(const std::string newType)
{
	this->type = newType;
}

void WrongCat::makeSound() const
{
	std::cout << "** MEOOOW **" << std::endl;
}
