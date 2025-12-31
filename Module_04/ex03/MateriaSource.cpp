#include "MateriaSource.hpp"

// Orthodox canonical form

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		templates[i] = NULL;
	std::cout << " constructor MateriaSource" << std::endl; 
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		delete templates[i];
	std::cout << " destructor MateriaSource" << std::endl; 
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for(int i = 0; i < 4; i++)
	{
		if(src.templates[i] != NULL)
			this->templates[i] = src.templates[i]->clone();
		else 
			this->templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator = (const MateriaSource& src)
{
	if(this == &src)
		return(*this);

			
	for(int i = 0; i < 4; i++)
	{
		if(this->templates[i] != NULL)
		{
			delete templates[i];
			this->templates[i] = NULL;
		}
	}

	for(int i = 0; i < 4; i++)
	{
		if(src.templates[i] != NULL)
			this->templates[i] = src.templates[i]->clone();
		else 
			this->templates[i] = NULL;
	}
	return(*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if(templates[i] == NULL)
		{
			this->templates[i] = m;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if(templates[i] != NULL && templates[i]->getType() == type)
			return(templates[i]->clone());
	}
	return(0);
}
