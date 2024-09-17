#include "MutantStack.hpp"

#include <iostream>
#include <list>

template<typename T>
void	tester(T &container)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	++it;
	--it;
	while (it != ite)
		std::cout << *it++ << std::endl;
	std::cout << "=====" << std::endl;
}

int	main(void)
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		tester(mstack);
		std::stack<int>	s(mstack);
	}
	{
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		list.pop_back();
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		tester(list);
	}
	return 0;
}