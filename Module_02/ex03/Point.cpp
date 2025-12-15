#include"Point.hpp"



Point::Point(): x(0), y(0)  // default constructor
{}


Point::Point(const float a, const float b): x(a), y(b) // parametrized constructor
{}

Point::Point(const Point& other): x(other.x), y(other.y) //copy constructor
{}

Point& Point::operator= (const Point& other)
{
	if(this == &other)
		return(*this);
	// we cannot do copy operator cuz the x and y are constant.	
	return(*this);
}

Point::~Point() {}