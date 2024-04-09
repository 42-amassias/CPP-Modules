#include "Point.hpp"

Fixed	_sign(
			const Point &p1,
			const Point &p2,
			const Point &p3
			)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(
		Point const a,
		Point const b,
		Point const c,
		Point const point
		)
{
	Fixed	d1;
	Fixed	d2;
	Fixed	d3;
	bool	has_neg;
	bool	has_pos;

	d1 = _sign(point, a, b);
	d2 = _sign(point, b, c);
	d3 = _sign(point, c, a);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return (!has_neg || !has_pos);
}
