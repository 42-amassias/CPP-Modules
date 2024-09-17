#include "Span.hpp"

#include <iostream>

void	t1(void)
{
	int					values[] = { 10, 20, 11, -1, 32, 50 };
	std::vector<int>	test(values, values + (size_t)(sizeof(values) / sizeof(values[0])));
	Span				span(10);

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

void	t2(void)
{
	Span	span(5);

	span.addNumber(6);
	span.addNumber(3);
	span.addNumber(17);
	span.addNumber(9);
	span.addNumber(11);

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
}

int	main(void)
{
	t2();
}