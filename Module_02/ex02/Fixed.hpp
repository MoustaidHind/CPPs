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

	// The 6 comparison operators: >, <, >=, <=, ==, and !=
	bool operator> (const Fixed& other) const;
	bool operator< (const Fixed& other) const;
	bool operator>= (const Fixed& other) const;
	bool operator<= (const Fixed& other) const;
	bool operator== (const Fixed& other) const;
	bool operator!= (const Fixed& other) const;

	// The 4 arithmetic operators: +, -, *, and /.
	Fixed operator+ (const Fixed& other) const;
	Fixed operator- (const Fixed& other) const;
	Fixed operator* (const Fixed& other) const;
	Fixed operator/ (const Fixed& other) const;

	// The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
	// 	post-decrement) operators, which will increase or decrease the fixed-point value by
	// 	the smallest representable ϵ, such that 1 + ϵ > 1.
	Fixed& operator++(); //pre-inc ++i
	Fixed operator++(int); //post-inc i++
	Fixed& operator--(); //pre-dec
	Fixed operator--(int); //post-dec


	//4 public overloaded STATIC member functions (min, max) with 
	//(references to fixed-point) and (references to constant fixed-point)
	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

};

std::ostream& operator<<(std::ostream &os, const Fixed& other);

#endif
