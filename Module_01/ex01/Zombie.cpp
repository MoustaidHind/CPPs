#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string new_name)
{
	this->name = new_name; // why this with (->) not (.)
}

Zombie::~Zombie()
{
	std::cout << name << " : destroyed" << std::endl;
}