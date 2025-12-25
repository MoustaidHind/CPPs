#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Attack_points = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap parametrized constructor called " << std::endl;
	Hit_points = 100;
	Energy_points = 100;
	Attack_points = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called " << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap copy assignment constructor called " << std::endl;
	if(this == &src)
		return (*this);

	ClapTrap::operator=(src);

	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void  FragTrap::highFivesGuys(void)
{
	std::cout << "High Fives Guys ✋ !! " << std::endl;
}
