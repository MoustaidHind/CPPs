#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>


class Fixed
{
private:
	static const int	_fractional_bits; // store the number of fractional bits. Its value will always be the integer literal 8.
	int					_value; // An integer to store the fixed-point number value.

public:
	Fixed(); // default constructor
	Fixed(const Fixed& other); // copy constructor
	Fixed(const int val); // parametrized constructor (constant integer)
	Fixed(const float val); // parametrized constructor (constant floating-point)
	Fixed& operator = (const Fixed& other); // copy assignment operator overload
	~Fixed(); // destructor

	int getRawBits( void ) const; // returns the raw value of the fixed-point value
	void setRawBits( int const raw ); // that sets the raw value of the fixed-point number
	float toFloat( void ) const; // converts the fixed-point value to a floating-point value.
	int toInt( void ) const; // that converts the fixed-point value to an integer value.
};

std::ostream& operator<<(std::ostream &os, const Fixed& other);

#endif
