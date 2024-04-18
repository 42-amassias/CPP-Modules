#include "Array.hpp"

#include <iostream>
#include <exception>

int	main(void)
{
	{
		Array<int>	a;

		try
		{
			int x = a[0];
			x += 1;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	{
		Array<int>	a(1);

		try
		{
			std::cout << "a[0] = " << a[0] << std::endl;
			a[0] = 1;
			std::cout << "a[0] = " << a[0] << std::endl;
			a[1] = 2;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
}