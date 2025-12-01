#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*w_type;

public:
	HumanB(){};
	HumanB(std::string n_name): name(n_name), w_type(NULL) {};

	void setWeapon(Weapon& w);
	void attack();
};

#endif
