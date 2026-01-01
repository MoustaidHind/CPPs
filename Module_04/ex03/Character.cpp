#include "Character.hpp"

// Orthodox canonical form

Character::Character()
{
	name = "defaultCharacter";
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if(inventory[i] != NULL)
		{
			delete(inventory[i]);
			inventory[i] = NULL;
		}
	}
}

Character::Character(std::string name)
{
	this->name = name;
	for(int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& src)
{
	this->name = src.getName();
	for(int i = 0; i < 4; i++)
	{
		if(src.inventory[i] != NULL)
			this->inventory[i] = src.inventory[i]->clone();
		else 
			this->inventory[i] = NULL;
	}
}

Character& Character::operator = (const Character& src)
{
	if(this == &src)
		return(*this);
	
	this->name = src.getName();
	
	for(int i = 0; i < 4; i++)
	{
		if(this->inventory[i] != NULL)
		{
			delete inventory[i];
			this->inventory[i] = NULL;
		}
	}

	for(int i = 0; i < 4; i++)
	{
		if(src.inventory[i] != NULL)
			this->inventory[i] = src.inventory[i]->clone();
		else 
			this->inventory[i] = NULL;
	}
	return(*this);
}

// behaviors
std::string const & Character::getName() const
{
	return(this->name);
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if(inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if(idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}

