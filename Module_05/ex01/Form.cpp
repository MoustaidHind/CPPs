#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox
Form::Form() : _nameF("defaultForm"), _isSigned(false), _gradeS(1), _gradeE(1) 
{}

Form::Form(const std::string name, const int gradeS, const int gradeE) : _nameF(name), _gradeS(gradeS), _gradeE(gradeE)
{
	_isSigned = false;
	if(getGradeS() < 1 || getGradeE() < 1)
		throw Form::GradeTooHighException();
	else if(getGradeS() > 150 || getGradeE() > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _nameF(src.getNameF()), _isSigned(src.getIsSigned()), _gradeS(src.getGradeS()), _gradeE(src.getGradeE())
{}

Form &Form::operator=(const Form &src)
{
	if (this == &src)
		return *this;

	_isSigned = src.getIsSigned();

	return *this;
}

Form::~Form() {}


// Getters
int Form::getGradeE() const {	return(_gradeE); }
int Form::getGradeS() const {	return(_gradeS); }
bool	Form::getIsSigned() const {	return(_isSigned); }
const std::string	Form::getNameF() const { return(_nameF); }


void Form::beSigned(Bureaucrat &bur)
{
	if(bur.getGrade() <= this->getGradeS()) // grade 1 is higher than grade 2.
		this->_isSigned = true;
	else 
		throw Form::GradeTooLowException();
}

// Overloaded function
std::ostream &operator<<(std::ostream &os, const Form &src)
{
	os << "Form Name: " << src.getNameF() << ", Is Signed: " << src.getIsSigned() <<
	", Grade Required to Sign: " << src.getGradeS() << 
	", Grade Required to Execute: " << src.getGradeE();
	return(os);
}
