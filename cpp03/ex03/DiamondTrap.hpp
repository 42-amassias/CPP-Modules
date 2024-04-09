#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap :
	public ScavTrap,
	public FragTrap
{
	public:
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &o);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &o);

		using	ScavTrap::attack;
		void	whoAmI(void);

	private:
		std::string	m_name;
};

#endif