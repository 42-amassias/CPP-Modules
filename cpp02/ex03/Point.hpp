#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& o);
		~Point(void);
	
		Point&			operator=(Point const& o);

		Point			operator+(Point const& o) const;
		Point			operator-(Point const& o) const;

		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;

	private:
		const Fixed	m_x;
		const Fixed	m_y;
};

std::ostream&	operator<<(std::ostream & o, Point const& point);

#endif