#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) :
	ClapTrap(name)
{
	m_hp = 100;
	m_ep = 50;
	m_ad = 20;
	std::cout << "ScavTrap " << m_name << " has become alive !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &o) :
	ClapTrap(o)
{
	std::cout << "ScavTrap " << m_name << " has become alive !" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << m_name << " ceased to exist !" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!canDoAction(std::string("attack ") + target))
		return ;
	--m_ep;
	std::cout
		<< "ScavTrap " << m_name << " attacks " << target
		<< ", causing " << m_ad << " points of damage !"
		<< std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (!canDoAction("go into gate keeper mode"))
		return ;
	std::cout
		<< "ScavTrap " << m_name
		<< " is now in gate keeper mode."
		<< std::endl;
}
