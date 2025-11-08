#include <iostream>

int main()
{
	std::string message = "HI THIS IS BRAIN";
	std::string &messageREF = message;

	std::string *messagePTR;
	messagePTR = &message;

	std::cout << "The memory address of the variable : " << &message << std::endl;
	std::cout << "The memory address held by PTR     : " << messagePTR << std::endl;
	std::cout << "The memory address held by REF     : " << &messageREF << std::endl << std::endl;

	std::cout << "The value of the variable   : " << message << std::endl;
	std::cout << "The value pointed to by PTR : " << *messagePTR << std::endl;
	std::cout << "The value pointed to by REF : " << messageREF << std::endl;
}