#include "Zombie.hpp"

Zombie::Zombie(std::string name) :
	m_name(name)
{
}

Zombie::Zombie(void) :
	m_name("")
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

void	Zombie::set_name(std::string name)
{
	m_name = name;
}

void	Zombie::announce(void) const
{
	std::cout << m_name << ": >: BraiiiiiiinnnzzzZ..." << std::endl;
}
