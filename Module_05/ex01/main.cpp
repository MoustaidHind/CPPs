#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    try
	{
        Bureaucrat bob("Bob", 10);
        Form contract("Contract", 20, 20);
        
        std::cout << bob << std::endl;
        std::cout << contract << std::endl;

        bob.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

	std::cout << "##############################################" << std::endl;

    try
	{
        Bureaucrat alice("alice", 150);
        Form secretDoc("SecretDoc", 1, 1);

        std::cout << alice << std::endl;
        std::cout << secretDoc << std::endl;

        alice.signForm(secretDoc);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}