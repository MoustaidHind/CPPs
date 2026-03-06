#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib> // srand
#include <ctime>   // time

int main()
{
    std::srand(std::time(NULL));

    try {
        Bureaucrat boss("The Boss", 1);
        std::cout << boss << std::endl;

        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("bob");
        PresidentialPardonForm pardon("alice");

        std::cout << "\n--- Shrubbery Creation ---" << std::endl;
        boss.signForm(shrub);
        boss.executeForm(shrub); 

        std::cout << "\n--- Robotomy Request ---" << std::endl;
        boss.signForm(robot);
		// std::cout << std::endl;
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);

        std::cout << "\n--- Presidential Pardon ---" << std::endl;
        boss.signForm(pardon);
        boss.executeForm(pardon);

    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Failure Case ---" << std::endl;
    try {
        Bureaucrat jone("jone", 150);
        RobotomyRequestForm robot2("job");

        jone.signForm(robot2);

        jone.executeForm(robot2);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}