#pragma once 

#include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade; // 1 (highest possible grade) to 150 (lowest possible grade)

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	// if out of range must throw the same exceptions as the constructor.
	void	incrementGrade(); 
	void	decrementGrade();

	const std::string	getName() const;
	int					getGrade() const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src); // <name>, bureaucrat grade <grade>
