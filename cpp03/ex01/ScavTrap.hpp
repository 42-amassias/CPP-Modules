#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap :
	public ClapTrap
{
	public:
		ScavTrap(std::string const& name);
		ScavTrap(ScavTrap const& o);
		~ScavTrap(void);

		ScavTrap&	operator=(ScavTrap const& o);

		void	attack(std::string const& target);

		void	guardGate(void);
};

#endif