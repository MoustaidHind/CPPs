#pragma once 

#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& src);
	WrongCat& operator=(const WrongCat& src);
	~WrongCat();

	std::string getType() const;
	void 		setType(const std::string newType);
	void makeSound() const;

};

