#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string m_type;

public:
	Weapon(){};
	Weapon(std::string type) : m_type(type){};

	void setType(std::string new_type);
	const std::string& getType();
};

#endif