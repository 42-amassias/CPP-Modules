#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap :
	virtual public ClapTrap
{
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &o);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &o);

		void	attack(const std::string &target);

		void	guardGate(void);
};

#endif