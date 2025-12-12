#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

/* CONSTRUCTORS */
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



/* GETTER && SETTER */
int Fixed::getRawBits( void ) const // returns the raw value of the fixed-point value
{
	/* const in the end 
	This member function is not allowed to modify the object.
	It cannot change any attribute of the class.
	It is a read-only function.
	*/
	return(_value);
}
void Fixed::setRawBits( int const raw ) // that sets the raw value of the fixed-point number
{
	_value = raw;
}



// CONVERTION 
int Fixed::toInt( void ) const // that converts the fixed-point value to an integer value
{
	return(_value / (1 << 8));
}

float Fixed::toFloat( void ) const  // that converts the fixed-point value to an floating-point value
{
	return((float)_value / (float)(1 << 8));
}



// function overloading 
std::ostream& operator<<(std::ostream &os, const Fixed& other)
{
	os << other.toFloat();
	return(os);
};




// The 6 comparison operators: >, <, >=, <=, ==, and != 
bool Fixed::operator>(const Fixed& other) const  // const : (promise to leave this object unchanged)
{
	if(this->_value > other._value)
		return(true);
	return(false);
}

bool Fixed::operator<(const Fixed& other) const
{
	if(this->_value < other._value)
		return(true);
	return(false);
}

bool Fixed::operator>=(const Fixed& other) const
{
	if(this->_value >= other._value)
		return(true);
	return(false);
}

bool Fixed::operator<=(const Fixed& other) const
{
	if(this->_value <= other._value)
		return(true);
	return(false);
}

bool Fixed::operator==(const Fixed& other) const
{
	if(this->_value == other._value)
		return(true);
	return(false);
}

bool Fixed::operator!=(const Fixed& other) const
{
	if(this->_value != other._value)
		return(true);
	return(false);
}



// The 4 arithmetic operators: +, -, *, and /
Fixed Fixed::operator+ (const Fixed& other)
{
	Fixed sum;

	sum.setRawBits(this->_value + other._value);
	return(sum);
}

Fixed Fixed::operator- (const Fixed& other)
{
	Fixed sub;

	sub.setRawBits(this->_value - other._value);
	return(sub);
}

Fixed Fixed::operator* (const Fixed& other)
{
	Fixed multi;

	multi.setRawBits(this->_value * other._value);
	return(multi);
}

Fixed Fixed::operator/ (const Fixed& other)
{
	Fixed sum;

	sum.setRawBits(this->_value / other._value);
	return(sum);
}


// The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
// 	post-decrement) operators, which will increase or decrease the fixed-point value by
// 	the smallest representable ϵ, such that 1 + ϵ > 1.

Fixed& Fixed::operator++()
{
	// Increments immediately, then returns the new value
	this->_value++;
	return(*this);
}

Fixed Fixed::operator++(int) // int parameter to makes the function signature different (post increment)
{
	// Returns the current value (a copy), then increments afterwards
	Fixed post_incr(*this); // call copy constructor

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
	// Returns the current value (a copy), then increments afterwards
	Fixed post_decr(*this); // call copy constructor

	this->_value++;
	return(post_decr);
}

//4 public overloaded STATIC member functions (min, max) with 
	//(references to fixed-point) and (references to constant fixed-point)
	// static Fixed& min(Fixed& f1, Fixed& f2);
	// static Fixed& min(const Fixed& f1, const Fixed& f2);
	// static Fixed& max(Fixed& f1, Fixed& f2);
	// static Fixed& max(const Fixed& f1, const Fixed& f2);

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if(f1._value > f2._value)
		return(f2);
	return(f1);
}

// Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) const
// {
// 	if(f1._value > f2._value)
// 		return(f2);
// 	return(f1);
// }