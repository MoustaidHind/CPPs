#pragma once 

#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string type;
public:
	AMateria(); // default 
	AMateria(std::string const & type); // parameterized
	AMateria(const AMateria& src); // copy
	AMateria& operator = (const AMateria& src); // copy assignment
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0; 
	virtual void use(ICharacter& target) = 0; 
};


