#include "PmergeMe.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>

#define NUM_DISPLAYED_ITEMS (5)

static
int	_to_int(
		std::string const& ratio
		);

template<class T>
void	_print_tab(
			T const& container
			)
{
	typename T::const_iterator itr(container.begin());

	for (size_t i = 0; i < NUM_DISPLAYED_ITEMS; ++i, ++itr)
	{
		if (itr == container.end())
			break ;
		std::cout << " " << *itr;
	}
}

int main(int argc, char **argv)
{
	std::deque<int>		deque;
	std::vector<int>	vector;
	int					t;

	for (int k = 1; k < argc; ++k)
	{
		try
		{
			t = _to_int(argv[k]);
		}
		catch (std::exception const& e)
		{
			std::cerr
				<< *argv
				<< ": "
				<< argv[k]
				<< " is not an integer"
				<< std::endl;
			return (EXIT_FAILURE);
		}
		deque.push_back(t);
		vector.push_back(t);
	}
	std::cout << "Before :";
	_print_tab<std::vector<int> >(vector);
	std::cout << std::endl;
	fjmi<std::deque<int> >(deque);
	fjmi<std::vector<int> >(vector);
	std::cout << "After :";
	_print_tab<std::vector<int> >(vector);
	std::cout << std::endl;
	
	return (EXIT_SUCCESS);
}

static
int	_to_int(
		std::string const& ratio
		)
{
	std::stringstream	ss;
	int					r;
	size_t				end;

	end = ratio.find_last_not_of(' ');
	end += ratio.find_last_not_of(' ') != std::string::npos ? 1 : 0;
	ss << ratio.substr(0, end);
	if (!(ss >> r) || !ss.eof())
		throw std::exception();
	return (r);
}
