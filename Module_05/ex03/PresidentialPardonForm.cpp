#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(target, 25, 5), target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return *this;
	AForm::operator=(src);
	target = src.target;
	return *this;
}
 
PresidentialPardonForm::~PresidentialPardonForm()
{}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if(executor.getGrade() > this->getGradeE())
		throw AForm::GradeTooLowException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
