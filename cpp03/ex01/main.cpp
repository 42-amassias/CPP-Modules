#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("user1");
	ScavTrap	b("user2");
	ClapTrap	c(b);

	return (0);
}