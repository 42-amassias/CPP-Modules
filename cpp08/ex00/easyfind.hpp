#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
void	easyfind(T& container, int value)
{
	std::cout
		<< (std::find(container.begin(), container.end(), value) != container.end()
			? "Found"
			: "Not found")
		<< std::endl;
}