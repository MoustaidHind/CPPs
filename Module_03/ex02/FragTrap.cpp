#include "FragTrap.hpp"

// default constructor
FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->Name = "defaultFrag";
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_points = 30;
}

// parametrized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parametrized constructor called " << std::endl;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_points = 30;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called " << std::endl;
	*this = src;
}

// copy assignment
FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap copy assignment constructor called " << std::endl;
	if(this == &src)
		return (*this);

	this->Name = src.Name;
	this->Hit_points = src.Hit_points;
	this->Energy_points = src.Energy_points;
	this->Attack_points = src.Attack_points;

	return(*this);
}

// destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void  FragTrap::highFivesGuys(void)
{
	std::cout << "High Fives Guys ✋✋ !! " << std::endl;
}
