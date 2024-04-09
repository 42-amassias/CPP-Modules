#include "Point.hpp"

Point::Point() :
	m_x(0.f),
	m_y(0.f)
{
}

Point::Point(const float x, const float y) :
	m_x(x),
	m_y(y)
{
}

Point::Point(const Point &o) :
	m_x(o.m_x),
	m_y(o.m_y)
{
}

Point::~Point()
{
}

Point	&Point::operator=(const Point &o)
{
	if (this == &o)
		return (*this);
	(Fixed)this->m_x = o.m_x;
	(Fixed)this->m_y = o.m_y;
	return (*this);
}

const Fixed	&Point::getX(void) const
{
	return (m_x);
}

const Fixed	&Point::getY(void) const
{
	return (m_y);
}

std::ostream	&operator<<(std::ostream &o, Point const &point)
{
	o << "(" << point.getX() << "," << point.getY() << ")";
	return (o);
}