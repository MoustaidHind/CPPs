#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
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
