#include "ClapTrap.hpp"


int main() {
    ClapTrap h1("NINA");

    h1.attack("Zoz"); 
    
    h1.takeDamage(5);
    
    h1.beRepaired(3);

    h1.takeDamage(5000); 

    h1.attack("Target2");
	h1.beRepaired(10);

    return 0;
}