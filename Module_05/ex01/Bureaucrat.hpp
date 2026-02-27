#pragma once 

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	// Orthodox
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	void	incrementGrade();
	void	decrementGrade();

	const std::string	getName() const;
	int					getGrade() const;

	void signForm(Form &form);

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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);
