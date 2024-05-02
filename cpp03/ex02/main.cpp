#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a("user1");
	FragTrap	b("user2");

	a.attack("the air");
	a.takeDamage(10);
	a.beRepaired(10);
	a.highFiveGuys();
	return (0);
}
