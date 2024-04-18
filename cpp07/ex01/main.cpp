#include "iter.hpp"

#include <iostream>

void	fun1(const std::string &str)
{
	std::cout << str << " ";
}

void	fun2(const std::string &str)
{
	std::cout << str.length() << std::endl;
}

int	main(void)
{
	std::string	strs[] = {
		"Hello",
		"world",
		"!"
	};
	iter(strs, 3, fun1);
	std::cout << std::endl;
	iter(strs, 3, fun2);
	return (0);
}
