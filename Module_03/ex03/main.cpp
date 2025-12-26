#include "DiamondTrap.hpp"

int main()
{
    std::cout << "-------------------------------------------------------" << std::endl;
    
    DiamondTrap monster("Monster");

    std::cout << "-------------------------------------------------------" << std::endl;

    monster.whoAmI();
    monster.guardGate();      // From ScavTrap
    monster.highFivesGuys();  // From FragTrap

    std::cout << "-------------------------------------------------------" << std::endl;

    monster.attack("Target-Z");
    monster.takeDamage(99);
    monster.beRepaired(50);

    return 0;
}