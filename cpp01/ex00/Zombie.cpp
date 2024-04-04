#include "Zombie.hpp"

Zombie::Zombie(std::string name) :
	m_name(name)
{
}
#ifdef DEBUG
Zombie::~Zombie(void)
{
	std::cout << "[" << m_name << "] Deleted" << std::endl;
}
#else
Zombie::~Zombie(void)
{
}
#endif

void	Zombie::announce(void) const
{
	std::cout << m_name << ": >: BraiiiiiiinnnzzzZ..." << std::endl;
}
