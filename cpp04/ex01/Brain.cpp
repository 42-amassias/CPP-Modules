#include "Brain.hpp"

Brain::Brain(void)
{
}

Brain::Brain(const Brain &o)
{
	*this = o;
}

Brain::~Brain(void)
{
}

Brain	&Brain::operator=(const Brain &o)
{
	if (this == &o)
		return (*this);
	for (size_t i = 0; i < IDEA_COUNT; ++i)
		m_ideas[i] = o.m_ideas[i];
	return (*this);
}
