#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    try
	{
        Bureaucrat bob("Bob", 10);
        Form contract_1("Contract_1", 20, 20);
        
        std::cout << bob << std::endl;
        std::cout << contract_1 << std::endl;

        bob.signForm(contract_1);
        std::cout << contract_1 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

	std::cout << "##############################################" << std::endl;

    try
	{
        Bureaucrat alice("alice", 150);
        Form Contract_2("Contract_2", 1, 1);

        std::cout << alice << std::endl;
        std::cout << Contract_2 << std::endl;

        alice.signForm(Contract_2);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}