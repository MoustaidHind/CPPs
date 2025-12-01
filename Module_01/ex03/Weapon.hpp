#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon(){};
	Weapon(std::string type) : type(type){};

	void setType(std::string new_type);
	const std::string& getType();
};

#endif