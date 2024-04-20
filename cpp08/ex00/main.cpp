#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vector;

	vector.push_back(10);
	vector.push_back(12);
	vector.push_back(20);
	vector.push_back(-1);
	easyfind(vector, 10);
	easyfind(vector, 11);
}