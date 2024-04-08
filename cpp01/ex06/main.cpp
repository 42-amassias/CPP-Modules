#include <iostream>

#include "Harl.hpp"

int	main(
		int argc,
		char *argv[]
		)
{
	Harl		harl;
	size_t		index(0);
	std::string	level;

	if (argc == 1)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		return (1);
	}
	level = std::string(argv[1]);
	while (index < 4 && level != Harl::g_levels[index])
		++index;
	switch (index)
	{
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("error");
			std::cout << std::endl;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("warning");
			std::cout << std::endl;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("info");
			std::cout << std::endl;
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("debug");
			std::cout << std::endl;
			break ;
		default:
			std::cout
				<< "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	};
	return (0);
}
