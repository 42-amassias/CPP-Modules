#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const& name) :
	ClapTrap(name),
	ScavTrap(name),
	FragTrap(name)
{
	m_name = name;
	ClapTrap::m_name = name + "_clap_name";
	FragTrap::m_hp = 100;
	FragTrap::m_ep = 50;
	FragTrap::m_ad = 30;
	std::cout << "DiamondTrap " << m_name << " has become alive !" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& o) :
	ClapTrap(o),
	ScavTrap(o),
	FragTrap(o)
{
	std::cout << "DiamondTrap " << m_name << " has become alive !" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << m_name << " ceased to exist !" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout
		<< "I am a DiamondTrap named " << m_name
		<< ", ClapTrap name: " << ClapTrap::m_name
		<< std::endl;
}
