#include "Weapon.hpp"

const std::string& Weapon::getType()
{
	return(m_type); 
}

void Weapon::setType(std::string new_type)
{
	m_type = new_type;
}
