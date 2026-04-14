#ifndef WHATEVER_HPP 
#define WHATEVER_HPP

#include <iostream>

// swap: Swaps the values of two given parameters. Does not return anything.
template <typename T>
void swap(T &a, T &b)
{
	T tmp = a; 
	a = b;
	b = tmp;

}

// min: Compares the two values passed as parameters and returns the smallest one.
// If they are equal, it returns the second one.
template <typename T>
T const &min(T const &a, T const &b)
{
	if(a > b || a == b)
		return(b);
	return(a);
}


// max: Compares the two values passed as parameters and returns the greatest one.
// If they are equal, it returns the second one.
template <typename T>
T const &max(T const &a, T const &b)
{
	if(a < b || a == b)
		return(b);
	return(a);
}

#endif

// why we use typename , what refere for