#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	if(this == &src)
		return(*this);
	return(*this);
}

Intern::~Intern()
{}

AForm* Intern::makeForm(const std::string formType, const std::string target)
{
	int i = 0;

	const std::string formstypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	while(i < 3)
	{
		if(formstypes[i] == formType)
		{
			std::cout << "Intern creates The " << formstypes[i] << std::endl;
			break;
		}
		i++;
	}

	switch (i)
	{
	case 0:
		return(new ShrubberyCreationForm(target));
	
	case 1:
		return(new RobotomyRequestForm(target));

	case 2:
		return(new PresidentialPardonForm(target));

	default:
		std::cout << "Intern cannot create [" << target << "]" << std::endl;
		return NULL;
	};


}

