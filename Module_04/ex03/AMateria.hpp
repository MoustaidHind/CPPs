#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include <iostream>
#include "ICharacter.hpp"


class AMateria
{
protected:
	std::string type;
public:
	AMateria(); // default 
	AMateria(std::string const & type); // parameterized
	AMateria(const AMateria& src); // copy
	AMateria& operator = (const AMateria& src); // copy assignment
	~AMateria();
	
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0; 
	virtual void use(ICharacter& target); 
};


#endif