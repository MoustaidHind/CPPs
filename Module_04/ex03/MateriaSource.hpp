#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

private:
	AMateria* templates[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& src);
	MateriaSource& operator = (const MateriaSource& src);
	~MateriaSource();

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};

