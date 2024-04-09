#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &o);
		~Point();
	
		Point	&operator=(const Point &o);

		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

	private:
		const Fixed	m_x;
		const Fixed	m_y;
};

std::ostream	&operator<<(std::ostream &o, Point const &point);

#endif