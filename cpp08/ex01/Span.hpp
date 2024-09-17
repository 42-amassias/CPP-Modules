#pragma once

#include <stdexcept>
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

			if (m_values.size() + range.size() > m_capacity)
				throw std::out_of_range("too many values in span");
			m_values.insert(m_values.end(), range.begin(), range.end());
		}

		int		shortestSpan(void) const;
		int		longestSpan(void) const;

	private:
		Span(void);

	private:
		unsigned int		m_capacity;
		std::vector<int>	m_values;
};