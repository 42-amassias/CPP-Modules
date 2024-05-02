#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const& name) :
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
	*this = o;
	std::cout << "ScavTrap " << m_name << " has become alive !" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << m_name << " ceased to exist !" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& o)
{
	if (this == &o)
		return (*this);
	ClapTrap::operator=(o);
	return (*this);
}

void	ScavTrap::attack(std::string const& target)
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
