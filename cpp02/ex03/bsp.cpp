#include "Point.hpp"

Fixed	_sign(
			Point const& p1,
			Point const& p2,
			Point const& p3
			)
{
	Point const	p13(p1 - p3);
	Point const	p23(p2 - p3);

	return (p13.getX() * p23.getY() - p23.getX() * p13.getY());
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
