#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap :
	virtual public ClapTrap
{
	public:
		FragTrap(std::string const& name);
		FragTrap(FragTrap const& o);
		~FragTrap(void);

		FragTrap&	operator=(FragTrap const& o);

		void	attack(std::string const& target);

		void	highFiveGuys(void);
};

#endif