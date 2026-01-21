#include "Bureaucrat.hpp"

// Orthodox
Bureaucrat::Bureaucrat() : _name("defaultName"), _grade(1)
{}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if(getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
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



// Getters
const std::string	Bureaucrat::getName() const { return(_name); }
int  Bureaucrat::getGrade() const { return(_grade); }


// Member functions 
void	Bureaucrat::incrementGrade()  // substract 2 become 1
{
	std::cout << "increment the grade of " << getName() << std::endl ;
	if(getGrade() <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade() // add 3 become 4
{
	std::cout << "decrement the grade of " << getName() << std::endl ;
	if(getGrade() >= 150)
		throw Bureaucrat::GradeTooLowException();	
	_grade++;
}
void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getNameF() << " form successfully." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getNameF() << 
		" because " ;
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const // print → "<bureaucrat> executed <form>"
{
	if(this->getGrade() > form.getGradeE())
		throw AForm::GradeTooLowException();

	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getNameF() << " form successfully." << std::endl;
}

// Overload function
std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << " , bureaucrat grade " << src.getGrade();
	return(os);
} 

