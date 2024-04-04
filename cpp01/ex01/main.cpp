#include "Zombie.hpp"

#define HORDE_SIZE 10

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*zombies;

	zombies = zombieHorde(HORDE_SIZE, "MC");
	for (size_t i = 0; i < HORDE_SIZE; ++i)
		zombies[i].announce();
	delete[] zombies;
}