#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap parametrized constructor called" << std::endl;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_points = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_points = 20;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called " << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& src) 
{
	std::cout << "ScavTrap copy assignment constructor called " << std::endl;

	if(this == &src)
		return(*this);

	ClapTrap::operator=(src);
	
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->Hit_points <= 0 || this->Energy_points <= 0)
	{
		std::cout << this->Name << " is Dead :( " << std::endl;
		return;
	}
	this->Energy_points--;

	std::cout << "------ ATTACK ------" << std::endl;
	std::cout << "ScavTrap [" << this->Name << "] attacks [" << target << "] , causing [" << this->Attack_points << "] points of damage! " << std::endl;
	std::cout << this->Name << "'s Hit point [" << this->Hit_points << "]" << std::endl;
	std::cout << this->Name << "'s Energy point [" << this->Energy_points << "]" << std::endl;
	std::cout << this->Name << "'s Attack point [" << this->Attack_points << "]\n" << std::endl;

}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
