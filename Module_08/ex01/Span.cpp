#include "Span.hpp"

Span::Span() {	N = 0; }

Span::Span(unsigned int n) { N = n; }

Span::Span(const Span& src) { *this = src; }

Span& Span::operator=(const Span& src)
{
	if(this == &src)
		return (*this);
	
	this->vec = src.vec;
	this->N = src.N;	
	
	return(*this);
}

Span::~Span() { this->vec.clear(); }


void Span::addNumber(int num)
{
	if (this->vec.size() >= N)
        throw std::out_of_range("RANGE ERROR : cannot add more elements !!!! ");
	this->vec.push_back(num);
};

unsigned int Span::shortestSpan()
{
	if (this->vec.size() < 2)
		throw std::length_error("SIZE ERROR : cannot get shortest Span !!!! ");
	
	unsigned int shortspan;
	unsigned int min;
	std::vector<int> copyVec = this->vec;
	
	std::sort(copyVec.begin(), copyVec.end()); // sort copy vector
	min = copyVec[1] - copyVec[0];

	for(std::vector<int>::iterator it = copyVec.begin(); it != copyVec.end() - 1; it++)
	{
		shortspan = *(it + 1) - *it;
		if(shortspan < min)
			min = shortspan;
	}
	return (min);
};

unsigned int Span::longestSpan()
{
	if (this->vec.size() < 2)
		throw std::length_error("SIZE ERROR : cannot get longest Span !!!! ");

	std::vector<int> copyVec = this->vec; // make a copy

	std::sort(copyVec.begin(), copyVec.end()); // sort copy vector

	return(*(copyVec.end() - 1) - *copyVec.begin()); // .begin() it returns an iterator (must be derefenced)
};


void Span::addnumbers(std::vector<int>::iterator start, std::vector<int>::iterator endd)
{
	unsigned int distance = std::distance(start, endd);

	if(this->vec.size() + distance > this->N)
		throw std::out_of_range("RANGE ERROR : cannot add more elements !!!! ");

	this->vec.insert(this->vec.end(), start, endd);
};

