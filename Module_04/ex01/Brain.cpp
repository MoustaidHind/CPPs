#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy Constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
}

Brain& Brain::operator=(const Brain& src)
{
	if(this == &src)
		return(*this);
	
	for(int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	
	return(*this);
}