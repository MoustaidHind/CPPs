#pragma once

#include "AForm.hpp"

#include <iostream>


class Intern
{
private:

public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	~Intern();

	AForm* makeForm(const std::string formType, const std::string target);
};