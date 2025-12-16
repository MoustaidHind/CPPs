#include "Point.hpp"

/*check if the P point is right or left the vectore*/
Fixed calc_orientation(Point const &a, Point const &b, Point const &p)
{
	Fixed res;

	res = (p.get_y()-a.get_y()) * (b.get_x()-a.get_x()) - (p.get_x()-a.get_x()) * (b.get_y()-a.get_y());

	return(res);
}



bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed si_1 = calc_orientation(a, b, point);
	Fixed si_2 = calc_orientation(b, c, point);
	Fixed si_3 = calc_orientation(c, a, point);
	

	if((si_1 > 0 && si_2 > 0 && si_3 > 0) || (si_1 < 0 && si_2 < 0 && si_3 < 0))
		return(true);

	return(false);
}

// still have confuse how the vector Z can check if the point is in or out the triangle 
// to watch -> https://www.youtube.com/results?search_query=Determinant+Formula
