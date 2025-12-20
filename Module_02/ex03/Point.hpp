#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float a, const float b);
		Point(const Point& other);
		Point& operator= (const Point& other);
		~Point();

		const Fixed get_x() const;
		const Fixed get_y() const;
};

#endif
