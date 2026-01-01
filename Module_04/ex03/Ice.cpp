#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria(src)
{
	*this = src;
}

Ice& Ice::operator = (const Ice& src)
{
	if(this == &src)
		return(*this);

	AMateria::operator=(src); 

	return (*this);
}

Ice::~Ice() {}


Ice* Ice::clone() const
{
	Ice* newIce = new Ice();
	return(newIce);
}


void  Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
