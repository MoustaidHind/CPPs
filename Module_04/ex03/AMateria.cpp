#include "AMateria.hpp"

AMateria::AMateria() : type("defaultType")
{
	std::cout << "default" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "parameterized" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	this->type = src.getType();
	std::cout << "copy" << std::endl;
}

AMateria& AMateria::operator = (const AMateria& src)
{
	std::cout << " copy assignment " << std::endl;

	if(this == &src)
		return(*this);

	this->type = src.getType();

	return (*this);
}


std::string const & AMateria::getType() const
{
	return(this->type);
}


void AMateria::use(ICharacter& target)
{
	//  do something;
}

