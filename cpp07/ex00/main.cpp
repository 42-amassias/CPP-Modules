#include "whatever.hpp"

#include <iostream>

int	main(void)
{
	int	a(10);
	int	b(20);
	int	r;

	std::cout << a << " | " << b << std::endl;
	swap(a, b);
	std::cout << a << " | " << b << std::endl;
	r = min(a, b);
	std::cout << r << std::endl;
	r = max(a, b);
	std::cout << r << std::endl;
	return (0);
}
