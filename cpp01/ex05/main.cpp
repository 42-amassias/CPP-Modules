#include <iostream>

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("Hello");
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	return (0);
}
