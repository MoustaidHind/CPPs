#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("defaultName"), _grade(1)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
	_grade = src.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return *this;

	_grade = src.getGrade();

	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string	Bureaucrat::getName() const
{
	return(_name);
}
int  Bureaucrat::getGrade() const
{
	return(_grade);
}


void	Bureaucrat::incrementGrade()  // substract 2 become 1
{
	if(getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "increment the grade of " << getName() << std::endl ;
	_grade--;
}

void	Bureaucrat::decrementGrade() // add 3 become 4
{
	if(getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "decrement the grade of " << getName() << std::endl ;
	_grade++;
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << " , bureaucrat grade " << src.getGrade() << std::endl;
	return(os);
}

