#include "Span.hpp"

#include <algorithm>

Span::Span(void) :
	m_capacity(0),
	m_values()
{
}

Span::Span(unsigned int n) :
	m_capacity(n),
	m_values()
{
}

Span::Span(Span const& o)
{
	*this = o;
}

Span::~Span(void)
{
}

Span&	Span::operator=(Span const& o)
{
	std::vector<int>::const_iterator	itr;

	if (this == &o)
		return (*this);
	m_values = o.m_values;
	m_capacity = o.m_capacity;
	return (*this);
}

void	Span::addNumber(int value)
{
	if (m_values.size() + 1 > m_capacity)
		throw std::out_of_range("too many values in span");
	m_values.push_back(value);
}

template<typename T>
void	id(const T &x) { }

int	Span::shortestSpan(void) const
{
	std::vector<int>::const_iterator	itr;
	int									span;

	if (m_values.size() <= 1)
		throw std::range_error("Not enough values to compute a shortest span.");
	span = longestSpan();
	for (itr = m_values.begin(); itr != m_values.end(); ++itr)
		span = std::min(
			span,
			std::abs(*itr - *std::min_element(itr + 1, m_values.end()))
		);
	return (span);
}

int	Span::longestSpan(void) const
{
	int	min;
	int	max;

	if (m_values.size() <= 1)
		throw std::range_error("Not enough values to compute a longest span.");
	min = *std::min_element(m_values.begin(), m_values.end());
	max = *std::max_element(m_values.begin(), m_values.end());
	return (max - min);
}
