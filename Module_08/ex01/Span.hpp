#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int N;
	std::vector<int> vec;

public:
	Span();
	Span(unsigned int n) ;
	Span(const Span& src); // deep copy to dont point to the same address 
	Span& operator=(const Span& src);
	~Span();


	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addnumbers(std::vector<int>::iterator beginn, std::vector<int>::iterator endd);
};




#endif