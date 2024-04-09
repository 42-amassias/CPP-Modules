#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>

# define IDEA_COUNT 100

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &o);
		~Brain(void);

		Brain	&operator=(const Brain &o);

	private:
		std::string	m_ideas[IDEA_COUNT];
};

#endif