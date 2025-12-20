#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>


class Fixed
{
private:
	int					_value;
	static const int	_fractional_bits;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int val);
	Fixed(const float val);
	Fixed& operator = (const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

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

	// The 4 increment/decrement (pre, post)
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	//4 public overloaded STATIC member functions (min, max)
	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream &os, const Fixed& other);

#endif
