#include "ScavTrap.hpp"


// default constructor
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->Name = "defaultScav";
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_points = 20;
}

// parametrized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap parametrized constructor called" << std::endl;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_points = 20;
}

//copy constructor
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called " << std::endl;
	*this = src;
}

// copy assignment
ScavTrap& ScavTrap::operator= (const ScavTrap& src) 
{
	std::cout << "ScavTrap copy assignment constructor called " << std::endl;

	if(this == &src)
		return(*this);

	this->Name = src.Name;
	this->Hit_points = src.Hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_points = src.Attack_points;
	
	return(*this);
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(Hit_points <= 0 || Energy_points <= 0)
	{
		std::cout << "[" << Name << "] is Dead 💀💀 " << std::endl;
		return;
	}
	Energy_points--;

	std::cout << "ScavTrap [" << Name << "] attacks 💥💥 [" << target << "] , causing [" << Attack_points << "] points of damage 🩸🩸 ! " << std::endl;
	std::cout << Name << "'s Hit point [" << Hit_points << "]" << std::endl;
	std::cout << Name << "'s Energy point [" << Energy_points << "]" << std::endl;
	std::cout << Name << "'s Attack point [" << Attack_points << "]\n" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode 🛡️🛡️ !! " << std::endl;
}
