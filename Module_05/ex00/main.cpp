#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat b1("bob", 15);
		std::cout << b1;
		b1.decrementGrade();
		std::cout << b1;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
        Bureaucrat b2("alice", 0);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	try {
        Bureaucrat boss("The Boss", 2);
        std::cout << boss;
        
        boss.incrementGrade();
        std::cout << boss;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}
