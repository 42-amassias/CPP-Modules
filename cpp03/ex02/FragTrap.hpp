#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap :
	public ClapTrap
{
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &o);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &o);

		void	attack(const std::string &target);

		void	highFiveGuys(void);
};

#endif