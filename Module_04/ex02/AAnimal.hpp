#pragma once 


#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal& src);
	AAnimal& operator=(const AAnimal& src);
	virtual ~AAnimal();

	std::string getType() const ;
	virtual void makeSound() const = 0;
};



