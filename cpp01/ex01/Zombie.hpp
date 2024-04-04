#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	set_name(std::string name);
		void	announce(void) const;

	private:
		std::string	m_name;
};

#endif