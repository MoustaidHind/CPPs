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
    Intern 		someRandomIntern;
    Bureaucrat	boss("Boss", 1); // Rank 1 to sign everything
    AForm* rrf;
    
    std::cout << "Create robotomy request ---->" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
	if(rrf)
	{
		try
		{
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
		}
		catch (std::exception &e)
		{
			std::cout << "Bureaucrat Error : " << e.what() << std::endl;
		}
		delete rrf;
	}

    std::cout << "\nCreate Shrubbery ---->" << std::endl;
    AForm*		shru;
    shru = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (shru)
    {
		boss.signForm(*shru);	
        delete shru;
    }

    std::cout << "\nInvalid Form ---->" << std::endl;
    AForm*		wrong;
    
    wrong = someRandomIntern.makeForm("pizza order", "Dominos");

    if (wrong)
    {
		boss.signForm(*wrong);	
        delete wrong;
    }
    return 0;
}
