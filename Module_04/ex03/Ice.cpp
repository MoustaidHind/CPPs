#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "default Ice" << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src)
{
	*this = src;
	std::cout << "copy" << std::endl;
}

Ice& Ice::operator = (const Ice& src)
{
	std::cout << " copy assignment " << std::endl;

	if(this == &src)
		return(*this);

	AMateria::operator=(src); 

	return (*this);
}

Ice::~Ice()
{
	std::cout << "destructor " << std::endl;
}


Ice* Ice::clone() const
{
	Ice* newIce = new Ice();
	return(newIce);
}


void  Ice::use(ICharacter& target)
{

	std::cout << "* shoots an ice bolt at" << target.getName() << " *" << std::endl;

	// name of the Character passed as a parameter
}
