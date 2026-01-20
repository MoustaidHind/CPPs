#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_nameF;
	bool				_isSigned;  // boolean indicating whether it is signed (at construction, it is not).
	const int			_gradeS; // constant grade required to sign it.
	const int			_gradeE; // constant grade required to execute it.

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

std::ostream &operator<<(std::ostream &os, const Form &src); // <name>, bureaucrat grade <grade>
