#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
	    ScavTrap scav("Serena");

        scav.takeDamage(50); 
        scav.beRepaired(10); 

        scav.attack("Target B");

        scav.guardGate();
        
    return (0);
}