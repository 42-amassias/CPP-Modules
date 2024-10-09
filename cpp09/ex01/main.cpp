#include <iostream>
#include <cstdlib>

#include "RPN.hpp"

static
void	_usage(
			char *pn
			);

int	main(
		int argc,
		char **argv
		)
{
	if (argc != 2)
		_usage(*argv);
	try
	{
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static
void	_usage(
			char *pn
			)
{
	std::cout << "Usage: " << pn << " expr" << std::endl;
	exit(EXIT_SUCCESS);
}
