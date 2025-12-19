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
	Fixed& operator = (const Fixed& other);
	Fixed(const float val);
	Fixed(const int val);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed& other);

#endif
