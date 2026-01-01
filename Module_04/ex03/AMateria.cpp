#include "AMateria.hpp"

AMateria::AMateria() : type("defaultType") {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& src)
{
	this->type = src.getType();
}

AMateria& AMateria::operator = (const AMateria& src)
{
	if(this == &src)
		return (*this);
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return(this->type);
}
