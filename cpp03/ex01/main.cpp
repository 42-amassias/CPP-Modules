#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("user1");
	ScavTrap	b("user2");

	a.attack("the air");
	a.takeDamage(10);
	a.beRepaired(10);
	a.guardGate();
	return (0);
}
