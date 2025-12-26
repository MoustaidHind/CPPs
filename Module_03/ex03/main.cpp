#include "DiamondTrap.hpp"

int main()
{
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "             TEST: DIAMONDTRAP CONSTRUCTION            " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    // 1. CONSTRUCTION
    // EXPECTED ORDER:
    // 1. ClapTrap Constructor (CALLED ONLY ONCE!)
    // 2. ScavTrap Constructor
    // 3. FragTrap Constructor
    // 4. DiamondTrap Constructor
    DiamondTrap monster("Monster");

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "             TEST: IDENTITY & SPECIAL METHODS          " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    // 2. WHO AM I
    // Expect: "My name is Monster and my ClapTrap name is Monster_clap_name"
    monster.whoAmI();

    // 3. SPECIAL ABILITIES
    // DiamondTrap inherits from both. It should be able to do BOTH special moves.
    monster.guardGate();      // From ScavTrap
    monster.highFivesGuys();  // From FragTrap

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "             TEST: STATS & ATTACK                      " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    // 4. ATTACK
    // The subject says: "use attack() from ScavTrap".
    // Expect: "ScavTrap Monster attacks..." (Not FragTrap, Not ClapTrap)
    monster.attack("Target-Z");

    // 5. CHECKING STATS
    // We can't print private vars directly, so we infer them or add getters if you have them.
    // Based on subject:
    // HP  = 100 (FragTrap)
    // EP  = 50  (ScavTrap)
    // AD  = 30  (FragTrap)
    
    std::cout << "\n[Testing Vitality...]" << std::endl;
    monster.takeDamage(99); // Should survive with 1 HP
    monster.beRepaired(50); // Should heal
    
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "             TEST: DESTRUCTION                         " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    // 6. DESTRUCTION
    // Reverse order of construction. 
    // IMPORTANT: ClapTrap destructor must be called ONLY ONCE at the very end.

    return 0;
}