#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <cstdlib> // For srand
#include <ctime>   // For time

int main()
{

	Intern	someRandomIntern;
	AForm*	rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
	// // Seed the random number generator for Robotomy
    // std::srand(std::time(0));

    // try {
    //     Bureaucrat boss("The Boss", 1);
    //     std::cout << boss << std::endl;

    //     ShrubberyCreationForm shrub("Home");
    //     RobotomyRequestForm robot("bob");
    //     PresidentialPardonForm pardon("alice");

    //     std::cout << "\n--- Shrubbery Creation ---" << std::endl;
    //     // Boss signs and executes
    //     boss.signForm(shrub);
    //     boss.executeForm(shrub); 

    //     std::cout << "\n--- Robotomy Request ---" << std::endl;
    //     boss.signForm(robot);
	// 	// std::cout << std::endl;
	// 	boss.executeForm(robot);
    //     boss.executeForm(robot);
    //     boss.executeForm(robot);
    //     boss.executeForm(robot);

    //     std::cout << "\n--- Presidential Pardon ---" << std::endl;
    //     boss.signForm(pardon);
    //     boss.executeForm(pardon);

    // }
    // catch (std::exception &e) {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }

    // std::cout << "\n--- Failure Case ---" << std::endl;
    // try {
    //     Bureaucrat jone("jone", 150); // Grade 150 (Weakest)
    //     RobotomyRequestForm robot2("job");

    //     // jone tries to sign
    //     jone.signForm(robot2); // Should print error message (not crash)

    //     // jone tries to execute (This should THROW an exception)
    //     jone.executeForm(robot2);
    // }
    // catch (std::exception &e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    return 0;
}