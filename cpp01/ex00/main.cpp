#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*zombie(NULL);

	zombie	= newZombie("The dynamics");
	zombie->announce();
	randomChump("Weakling");
	delete zombie;
}