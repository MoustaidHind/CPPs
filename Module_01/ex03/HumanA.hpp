#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon& w_type;

public:
	HumanA(std::string n_name, Weapon& n_type) : name(n_name), w_type(n_type){};
	~HumanA(){};
	void attack();
};

#endif