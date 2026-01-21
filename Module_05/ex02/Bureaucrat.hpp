#pragma once 

#include <iostream>
#include "AForm.hpp"


class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade; // 1 (highest possible grade) to 150 (lowest possible grade)

public:
	// Orthodox
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	// if out of range must throw the same exceptions as the constructor.
	void	incrementGrade();  // substract 2 become 1
	void	decrementGrade(); // add 3 become 4

	const std::string	getName() const;
	int					getGrade() const;

	void signForm(AForm &form);

	class GradeTooHighException : public std::exception {
		public :
		virtual const char* what() const throw()
		{
			return "The Grade is too High!";
		}
	};

	class GradeTooLowException : public std::exception {
		public :
		virtual const char* what() const throw()
		{
			return "The Grade is too Low!";
		}
	};


	void executeForm(AForm const & form) const; // print → "<bureaucrat> executed <form>"
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src); // <name>, bureaucrat grade <grade>


// try catch throw. (exception& e)
// costum exception + virtual function
// how exceptions work internally