#pragma once 

#include <iostream>
#include "AForm.hpp"


class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	void	incrementGrade(); 
	void	decrementGrade();

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


	void executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);
