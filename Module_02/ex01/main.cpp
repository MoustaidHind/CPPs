#include "Fixed.hpp"

int main( void ) 
{
	Fixed a; //def
	Fixed b( a ); //copy -> get
	Fixed c; // def

	c = b; // copy assi -> get

	std::cout << a.getRawBits() << std::endl; // get
	std::cout << b.getRawBits() << std::endl; // get
	std::cout << c.getRawBits() << std::endl; // get

	return 0;
}