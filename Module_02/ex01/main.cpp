#include "Fixed.hpp"

int main( void )
{
	Fixed		a;//de
	Fixed const b( 10 );//int const
	Fixed const c( 42.42f );//float const
	Fixed const d( b );// copy + operator

	a = Fixed( 1234.4321f ); //float + oparator + destroy tmp object

	std::cout << "a is " << a << std::endl; // float 1234.4321f -> 1234.4321f * 2⁸ -> 1234.4321f / 2⁸ 
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	return 0;
}
