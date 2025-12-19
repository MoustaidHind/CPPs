#include "ClapTrap.hpp"


int main() {
    ClapTrap h1("Bob");

    // Test 1: Attack and lose energy
    h1.attack("Zoz"); 
    
    // Test 2: Take damage (verify HP goes down)
    h1.takeDamage(5);
    
    // Test 3: Repair (verify HP goes up and Energy goes down)
    h1.beRepaired(3);

    // Test 4: Take fatal damage (verify it stops at 0 and doesn't underflow)
    h1.takeDamage(5000); 

    // Test 5: Try to act while dead (Should print "You are dead")
    h1.attack("Target2");
    h1.beRepaired(10);

    return 0;
}