#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int i)
{
	
	typename T::iterator val = std::find(container.begin(), container.end(), i);
	if(val == container.end())
		throw std::exception();
	else
		return (val);
};



#endif