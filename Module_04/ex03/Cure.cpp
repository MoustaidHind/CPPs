#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "default cure" << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src)
{
	*this = src;
	std::cout << "copy" << std::endl;
}

Cure& Cure::operator = (const Cure& src)
{
	std::cout << " copy assignment " << std::endl;

	if(this == &src)
		return(*this);

	AMateria::operator=(src); 

	return (*this);
}

Cure::~Cure()
{
	std::cout << "destructor " << std::endl;
}


Cure* Cure::clone() const
{
	Cure* newCure = new Cure();
	return(newCure);
}


void  Cure::use(ICharacter& target)
{
	std::cout << "* heals "  << "name" << "’s wounds *" << std::endl;

	// name of the Character passed as a parameter
}
