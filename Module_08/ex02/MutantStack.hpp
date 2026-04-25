#ifndef MUTANTSTACK
#define MUTANTSTACK


#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack(){};
	MutantStack(const MutantStack& src) : std::stack<T>(src) {};
	MutantStack& operator=(const MutantStack& src) 
	{
		if(this == &src)
			return(*this);

		std::stack<T>::operator=(src);
		return (*this);
	};
	~MutantStack(){};


	iterator begin() { return( std::stack<T>::c.begin() ); };
	iterator end() { return( std::stack<T>::c.end() ); };
};



#endif
