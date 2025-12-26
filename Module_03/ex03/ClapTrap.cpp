#include "ClapTrap.hpp"

// default constructor
// is name initialized by default with empty string ??
ClapTrap::ClapTrap() : Hit_points(10), Energy_points(10), Attack_points(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

//parametrized constructor
ClapTrap::ClapTrap(std::string name) : Name(name), Hit_points(10), Energy_points(10), Attack_points(0)
{
	std::cout << "ClapTrap parametrized constructor called " << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy constructor called " << std::endl;

	Name = other.Name;
	Hit_points = other.Hit_points;
	Energy_points = other.Energy_points;
	Attack_points = other.Attack_points;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment constructor called " << std::endl;

	if(this == &other)
		return(*this);

	Name = other.Name;
	Hit_points = other.Hit_points;
	Energy_points = other.Energy_points;
	Attack_points = other.Attack_points;

	return(*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(Hit_points <= 0 || Energy_points <= 0)
	{
		std::cout << "[" << Name << "] is Dead :( " << std::endl;
		return;
	}
	Energy_points--;
	std::cout << "------ ATTACK ------" << std::endl;
	std::cout << "ClapTrap [" << Name << "] attacks [" << target << "] , causing [" << Attack_points << "] points of damage! " << std::endl;
	std::cout << Name << "'s Hit point [" << Hit_points << "]" << std::endl;
	std::cout << Name << "'s Energy point [" << Energy_points << "]" << std::endl;
	std::cout << Name << "'s Attack point [" << Attack_points << "]\n" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(Hit_points <= 0) // just check hit points , not check for energy cuz we dont use it 
	{
		std::cout << "[" << Name << "] is Dead :( " << std::endl;
		return;
	}
	if(Hit_points <= amount) // prevent underflow
		Hit_points = 0;
	else
		Hit_points -= amount;
	
	std::cout << "------ TAKE DAMAGE ------" << std::endl;
	std::cout << "[" << Name << "] takes [" << amount << "] damage " <<  std::endl;
	std::cout << Name << "'s Hit point [" << Hit_points << "]" << std::endl;
	std::cout << Name << "'s Energy point [" << Energy_points << "]" << std::endl;
	std::cout << Name << "'s Attack point [" << Attack_points << "]\n" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(Hit_points <= 0 || Energy_points <= 0)
	{
		std::cout << "[" << Name << "] is Dead :( " << std::endl;
		return;
	}
	Hit_points += amount;
	Energy_points--;

	std::cout << "------ REPAIRED ------" << std::endl;
	std::cout << "[" << Name << "] Repaired itself, getting back [" << amount << "] hit points " << std::endl;
	std::cout << Name << "'s Hit point [" << Hit_points << "]" << std::endl;
	std::cout << Name << "'s Energy point [" << Energy_points << "]" << std::endl;
	std::cout << Name << "'s Attack point [" << Attack_points << "]\n" << std::endl;

}
