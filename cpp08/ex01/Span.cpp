#include "Span.hpp"

#include <stdexcept>
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
	if (m_values.size() + 1 >= m_capacity)
		throw std::out_of_range("too many values in span");
	m_values.push_back(value);
}

int	Span::shortestSpan(void) const
{
	std::vector<int>::const_iterator	itr_a;
	std::vector<int>::const_iterator	itr_b;
	int									span;

	span = longestSpan();
	for (itr_a = m_values.begin(); itr_a != m_values.end(); ++itr_a)
		for (itr_b = itr_a + 1; itr_b != m_values.end(); ++itr_b)
			if (std::abs(*itr_a - *itr_b) < span)
				span = std::abs(*itr_a - *itr_b);
	return (span);
}

#include <iostream>

int	Span::longestSpan(void) const
{
	std::vector<int>::const_iterator	min;
	std::vector<int>::const_iterator	max;

	if (m_values.size() <= 1)
		throw std::range_error("Not enough values to compute a shortest span.");
	min = std::min_element(m_values.begin(), m_values.end());
	max = std::max_element(m_values.begin(), m_values.end());
	return (*max - *min);
}
