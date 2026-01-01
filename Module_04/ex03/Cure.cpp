#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& src) : AMateria(src)
{
	*this = src;
}

Cure& Cure::operator = (const Cure& src)
{

	if(this == &src)
		return(*this);

	AMateria::operator=(src); 

	return (*this);
}

Cure::~Cure() {}

Cure* Cure::clone() const
{
	Cure* newCure = new Cure();
	return(newCure);
}


void  Cure::use(ICharacter& target)
{
	std::cout << "* heals "  << target.getName() << "'s wounds *" << std::endl;
}
