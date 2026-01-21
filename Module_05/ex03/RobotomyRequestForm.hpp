#pragma once

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string target;
public:
	// orthodox
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
};

// is i should remove default constructor ? 