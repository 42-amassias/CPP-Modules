#pragma once

#include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const& o);
		~Span(void);

		Span&	operator=(Span const& o);

		void	addNumber(int value);

		template<typename T>
		void	addNumbers(T range)
		{
			typename T::iterator	itr;

			for (itr = range.begin(); itr != range.end(); ++itr)
				addNumber(*itr);
		}

		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		Span(void);

	private:
		unsigned int		m_capacity;
		std::vector<int>	m_values;
};