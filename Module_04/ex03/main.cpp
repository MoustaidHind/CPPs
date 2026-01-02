#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n---- Fill inventory & unknown materia ----" << std::endl;

	tmp = src->createMateria("fire"); 
    if (tmp == NULL)
        std::cout << "unknown type" << std::endl;

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    
    AMateria* extra = src->createMateria("ice");
    me->equip(extra); // Should do nothing
    std::cout << "item was not equipped" << std::endl;    
    delete extra; 

    std::cout << "\n---- deep copy ----" << std::endl;
    Character* original = new Character("Original");
    original->equip(new Ice());
    
    // Create copy
    Character* copy = new Character(*original); // Call Copy Constructor
    
    delete original;
    
    std::cout << "Copy name: " << copy->getName() << std::endl;
    copy->use(0, *bob); // print "shoots an ice bolt"

	std::cout << "\n---- unequip test -----" << std::endl;
	AMateria* newMateria = new Cure();
	copy->equip(newMateria);
    copy->unequip(1);
    copy->use(1, *bob); // Should do nothing 
    std::cout << "no action printed " << std::endl;

	delete newMateria;
    delete bob;
    delete me;
    delete src;
    delete copy;
    
    return 0;
}
