#include "DiamondTrap.hpp"

// default constructor
DiamondTrap::DiamondTrap()
{
	this->Name = "defaultDiamond";
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_points  = FragTrap::Attack_points;
	std::cout << "DiamondTrap constructor called" << std::endl;

}

// parametrized constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->Name = name;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_points  = FragTrap::Attack_points;
	std::cout << "DiamondTrap parametrized constructor called" << std::endl;
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->Name = src.Name;
	this->Hit_points = src.Hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_points = src.Attack_points;
	std::cout << "DiamondTrap Copy constructor called " << std::endl;
}

// copy assignment
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	if(this == &src)
		return(*this);

	this->Name = src.Name;
	this->Hit_points = src.Hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_points = src.Attack_points;
	std::cout << "DiamondTrap copy assignment constructor called " << std::endl;

	return(*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is [" << this->Name << "] and my ClapTrap name is [" << ClapTrap::Name << "] ." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
