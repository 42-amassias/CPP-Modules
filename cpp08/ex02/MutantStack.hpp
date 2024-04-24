#pragma once

#include <stack>
#include <deque>

template<typename T, class Container = std::deque<T> >
class MutantStack :
	public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator	iterator;

		MutantStack(void)
		{
		}

		~MutantStack(void)
		{
		}

		MutantStack&	operator=(MutantStack const& o)
		{
			std::stack<T,Container>::operator=(o);
			return (*this);
		}

		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}

};