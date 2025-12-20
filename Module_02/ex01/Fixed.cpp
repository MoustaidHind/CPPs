#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	// _value = other.getRawBits();
	*this = other;
}

Fixed& Fixed::operator= (const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this == &other)
		return (*this);
	
	_value = other.getRawBits();
	
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return(_value);
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(val * (1 << _fractional_bits));
}

Fixed::Fixed(const float val)
{
	std::cout << "float constructor called" << std::endl;
	setRawBits(roundf(val * (1 << _fractional_bits)));
}

float Fixed::toFloat( void ) const
{
	return((float)this->getRawBits() / (float)(1 << _fractional_bits));
}

int Fixed::toInt( void ) const
{
	return(this->getRawBits() / (1 << _fractional_bits));
}

std::ostream& operator<<(std::ostream &os, const Fixed& other)
{
	os << other.toFloat();
	return(os);
}
