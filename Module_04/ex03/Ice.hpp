#pragma once 

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice : public AMateria
{

public:
	Ice();
	Ice(const Ice& src); // copy
	Ice& operator = (const Ice& src); // copy assignment
	~Ice();

	Ice* clone() const;
	void  use(ICharacter& target); 

};

