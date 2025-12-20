#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

/* CONSTRUCTORS */
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed& other)
{
	*this = other; 
}
Fixed& Fixed::operator= (const Fixed& other)
{
	if(this == &other)
		return (*this);	
	_value = other.getRawBits();
	return(*this);
}
Fixed::~Fixed() {}

Fixed::Fixed(const int val)
{
	setRawBits(val * (1 << _fractional_bits));
}

Fixed::Fixed(const float val)
{
	setRawBits(roundf(val * (1 << _fractional_bits)));
}

/* GETTER && SETTER */
int Fixed::getRawBits( void ) const 
{
	return(_value);
}
void Fixed::setRawBits( int const raw )
{
	_value = raw;
}


// CONVERTION 
int Fixed::toInt( void ) const
{
	return(this->getRawBits() / (1 << _fractional_bits));
}

float Fixed::toFloat( void ) const
{
	return((float)this->getRawBits() / (float)(1 << _fractional_bits));
}


// function overloading 
std::ostream& operator<<(std::ostream &os, const Fixed& other)
{
	os << other.toFloat();
	return(os);
};

// The 6 comparison operators: >, <, >=, <=, ==, and != 
bool Fixed::operator>(const Fixed& other) const
{
	if(this->getRawBits() > other.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator<(const Fixed& other) const
{
	if(this->getRawBits() < other.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if(this->getRawBits() >= other.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if(this->getRawBits() <= other.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator==(const Fixed& other) const
{
	if(this->getRawBits() == other.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator!=(const Fixed& other) const
{
	if(this->getRawBits() != other.getRawBits())
		return(true);
	return(false);
}


// The 4 arithmetic operators: +, -, *, and /
Fixed Fixed::operator+ (const Fixed& other) const
{
	Fixed sum;

	sum.setRawBits(this->getRawBits() + other.getRawBits());
	return(sum);
}

Fixed Fixed::operator- (const Fixed& other) const
{
	Fixed sub;

	sub.setRawBits(this->getRawBits() - other.getRawBits());
	return(sub);
}

Fixed Fixed::operator* (const Fixed& other) const
{
	Fixed multi;

	multi.setRawBits(((long long)this->getRawBits() * other.getRawBits()) / (1 << _fractional_bits));
	return(multi);
}

Fixed Fixed::operator/ (const Fixed& other) const
{
	Fixed devi;

	devi.setRawBits(((long long)this->getRawBits() * (1 << _fractional_bits)) / other.getRawBits());
	return(devi);
}

// The 4 increment/decrement (pre, post)
Fixed& Fixed::operator++()
{
	this->_value++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed post_incr(*this);

	this->_value++;
	return(post_incr);
}

Fixed& Fixed::operator--()
{
	this->_value--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed post_decr(*this);

	this->_value--;
	return(post_decr);
}

//4 public overloaded STATIC member functions (min, max) 
Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if(f1.getRawBits() > f2.getRawBits())
		return(f2);
	return(f1);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if(f1.getRawBits() > f2.getRawBits())
		return(f2);
	return(f1);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if(f1.getRawBits() > f2.getRawBits())
		return(f1);
	return(f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if(f1.getRawBits() > f2.getRawBits())
		return(f1);
	return(f2);
}
