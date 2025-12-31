#pragma once

#include <iostream>

class AMateria; // FORWARD DECLARATION

class ICharacter 
{
	public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

// why i should use interface even it does do nothing, just define functions 
// if we call interface how it work 
// why interface have destructor and it does not constructed 

