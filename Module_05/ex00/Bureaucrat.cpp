#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return *this;
}

Bureaucrat::~Bureaucrat()
{
}
