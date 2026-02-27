#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_nameF;
	bool				_isSigned;
	const int			_gradeS;
	const int			_gradeE;

public:
	// Orthodox
	Form();
	Form(const std::string name, const int gradeS,const int gradeE);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();

	// getters
	const std::string	getNameF() const;
	bool				getIsSigned() const;
	int					getGradeS() const;
	int					getGradeE() const;

	void beSigned(Bureaucrat &bur);

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

std::ostream &operator<<(std::ostream &os, const Form &src);
