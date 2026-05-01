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
	Span(const Span& src);
	Span& operator=(const Span& src);
	~Span();


	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	
	template <typename iter>
	void addnumbers(iter beginn, iter endd)
	{
		unsigned int distance = std::distance(beginn, endd);

		if(this->vec.size() + distance > this->N)
			throw std::out_of_range("RANGE ERROR : cannot add more elements !!!! ");

		this->vec.insert(this->vec.end(), beginn, endd);
	};
};



#endif