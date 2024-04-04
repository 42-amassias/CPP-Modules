#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;

	private:
		std::string	m_name;
};

#endif