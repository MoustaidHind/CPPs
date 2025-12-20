#include"Point.hpp"

Point::Point(): x(0), y(0)
{}

Point::Point(const float a, const float b): x(a), y(b)
{}

Point::Point(const Point& other): x(other.x), y(other.y)
{}

Point& Point::operator= (const Point& other)
{
	if(this == &other)
		return(*this);
	return(*this);
}

const Fixed Point::get_x() const
{
	return(x);
}

const Fixed Point::get_y() const
{
	return(y);
}

Point::~Point() {}