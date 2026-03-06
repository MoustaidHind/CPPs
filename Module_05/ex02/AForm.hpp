#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string	_nameF;
	bool				_isSigned;
	const int			_gradeS;
	const int			_gradeE;

public:
	AForm();
	AForm(const std::string name, const int gradeS,const int gradeE);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	const std::string	getNameF() const;
	bool				getIsSigned() const;
	int					getGradeS() const;
	int					getGradeE() const;

	void beSigned(Bureaucrat &bur);

	class GradeTooHighException : public std::exception {
		public :
		virtual const char* what() const throw()
		{
			return "The Grade is too High !!";
		}
	};

	class GradeTooLowException : public std::exception {
		public :
		virtual const char* what() const throw()
		{
			return "The Grade is too Low !!";
		}
	};

	class FormNotSignedException : public std::exception {
		public :
		virtual const char* what() const throw()
		{
			return "The Form Not Signed Yet !!";
		}
	};
	
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &src);
