#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0) // default constructor
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) // copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	// _value = other.getRawBits();
	*this = other; // ->  [[ WHY THAT WORK, WHEN THE OPERATOR= NEEDS TWO EXISTING OBJECTS ]]
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
	return(_value);
}

void Fixed::setRawBits( int const raw ) // that sets the raw value of the fixed-point number
{
	_value = raw;
}

Fixed::Fixed(const int val)// parametrized constructor takes a constant integer as a parameter
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(val * (1 << 8));
}

Fixed::Fixed(const float val)// parametrized constructor takes a constant floating-point number
{
	std::cout << "float constructor called" << std::endl;
	setRawBits(roundf(val * (1 << _fractional_bits)));
}

int Fixed::toInt( void ) const // that converts the fixed-point value to an integer value
{
	return(_value / (1 << 8));
}

float Fixed::toFloat( void ) const  // that converts the fixed-point value to an floating-point value
{
	return((float)_value / (float)(1 << 8));
}

std::ostream& operator<<(std::ostream &os, const Fixed& other)
{
	os << other.toFloat();
	return(os);
};