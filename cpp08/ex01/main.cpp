#include "Span.hpp"

#include <iostream>

int	main(void)
{
	Span	span(10);
	int	values[] = { 10, 20, 11, -1, 32, 50 };
	std::vector<int>	test(values, values + (size_t)(sizeof(values) / sizeof(values[0])));

	try
	{
		span.addNumbers(test);
		span.addNumber(7);
		std::cout << span.longestSpan() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		span.addNumber(10);
		span.addNumber(20);
		span.addNumber(11);
		span.addNumber(-1);
		span.addNumber(32);
		span.addNumber(50);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}