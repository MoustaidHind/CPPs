#include "FragTrap.hpp"

int main()
{
    FragTrap frag("frag");

    frag.highFivesGuys();

    frag.attack("Target3");
    frag.takeDamage(50);
    frag.beRepaired(20);

    return 0;
}