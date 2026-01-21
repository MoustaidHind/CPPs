#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox
AForm::AForm() : _nameF("defaultAForm"), _isSigned(false), _gradeS(1), _gradeE(1) 
{}

AForm::AForm(const std::string name, const int gradeS, const int gradeE) : _nameF(name), _gradeS(gradeS), _gradeE(gradeE)
{
	_isSigned = false;
	if(getGradeS() < 1 || getGradeE() < 1)
		throw AForm::GradeTooHighException();
	else if(getGradeS() > 150 || getGradeE() > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _nameF(src.getNameF()), _isSigned(src.getIsSigned()), _gradeS(src.getGradeS()), _gradeE(src.getGradeE())
{}

AForm &AForm::operator=(const AForm &src)
{
	if (this == &src)
		return *this;

	_isSigned = src.getIsSigned();

	return *this;
}

AForm::~AForm() {}


// Getters
int AForm::getGradeE() const {	return(_gradeE); }
int AForm::getGradeS() const {	return(_gradeS); }
bool	AForm::getIsSigned() const {	return(_isSigned); }
const std::string	AForm::getNameF() const { return(_nameF); }


void AForm::beSigned(Bureaucrat &bur)
{
	if(bur.getGrade() <= this->getGradeS()) // grade 1 is higher than grade 2.
		this->_isSigned = true;
	else 
		throw AForm::GradeTooLowException();
}

// Overloaded function
std::ostream &operator<<(std::ostream &os, const AForm &src)
{
	os << "AForm Name: " << src.getNameF() << ", Is Signed: " << src.getIsSigned() <<
	", Grade Required to Sign: " << src.getGradeS() << 
	", Grade Required to Execute: " << src.getGradeE();
	return(os);
}
