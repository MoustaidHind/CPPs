#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(target, 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return *this;
	AForm::operator=(src);
	target = src.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeE())
		throw AForm::GradeTooLowException();

	std::cout << "**Drilling noises** .. Vrr ... Vrrrrrr... " << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully !!" << std::endl;
	else
		std::cout << "Robotomy failed !! on " << target << std::endl;
}
