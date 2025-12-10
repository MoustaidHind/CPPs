#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0) // default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) //: _value(other.getRawBits()) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	// _value = other.getRawBits();
	*this = other;
}

Fixed& Fixed::operator= (const Fixed& other)  // copy assignment operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this == &other)
		return (*this);
	
	_value = other.getRawBits();
	
	return(*this);
}

Fixed::~Fixed() // destructor
{
	std::cout << "Destructor called" << std::endl;
}

/*
--> const in the end 
This member function is not allowed to modify the object.
It cannot change any attribute of the class.
It is a read-only function.
*/
int Fixed::getRawBits( void ) const // returns the raw value of the fixed-point value
{
	std::cout << "getRawBits member function called" << std::endl;
	return(_value);
}

void Fixed::setRawBits( int const raw ) // that sets the raw value of the fixed-point number
{
	_value = raw;
}