#include "Point.hpp"

#include <iostream>

bool bsp(
		const Point a,
		const Point b,
		const Point c,
		const Point point
		);

int	main(void)
{
	Point	a(2.f, 3.f);
	Point	b(0.f, 0.f);
	Point	c(4.f, 0.f);
	Point	point(2.f, 1.0f);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "point: " << point << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "Inside";
	else
		std::cout << "Outside";
	std::cout << std::endl;
	return (0);
}

//..#..
//.....
//..@..
//#...#