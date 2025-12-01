#include "HumanB.hpp"


void HumanB::attack()
{
	if(!w_type)
		std::cout << name << " has no weapon !" << std::endl;
	else
		std::cout << name << " attacks with their " << (*w_type).getType() << std::endl;
}

void HumanB::setWeapon(Weapon& n_type)
{
	w_type = &n_type;
}

