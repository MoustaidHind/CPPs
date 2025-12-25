#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap parametrized constructor called" << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_points = 20;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_points = 20;
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
	if(Hit_points <= 0 || Energy_points <= 0)
	{
		std::cout << Name << " is Dead :( " << std::endl;
		return;
	}
	Energy_points--;

	std::cout << "ScavTrap " << Name << " attacks " << target << " , causing " << Attack_points << " points of damage! " << std::endl;
	std::cout << Name << "'s Hit point [" << Hit_points << "]" << std::endl;
	std::cout << Name << "'s Energy point [" << Energy_points << "]\n" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
