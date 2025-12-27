#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    {
	    ScavTrap scav("Serena");

        scav.takeDamage(50); 
        scav.beRepaired(10); 

        scav.attack("Target B");

        scav.guardGate();

    }
    {
        //virtual destructor use case
        std::cout << "---------------------\n";
        ClapTrap *ptr = new ScavTrap("h1");
        delete ptr;
    }
        
    return (0);
}
