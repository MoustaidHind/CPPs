#include "Base.hpp"
#include "type.hpp"
#include <iostream>

int main()
{
	std::srand(std::time(NULL));
	
    std::cout << "Generating a random object...\n" << std::endl;
    Base* derived = generate();


    std::cout << "Pointer version Result: ";
    identify(derived);
    std::cout << "\n--------------------------------" << std::endl;


    std::cout << "Reference version Result: ";
    identify(*derived);
    std::cout << "\n--------------------------------" << std::endl;

	
    delete derived;

}