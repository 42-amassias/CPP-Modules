#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) :
	ClapTrap(name)
{
	m_hp = 100;
	m_ep = 100;
	m_ad = 30;
	std::cout << "FragTrap " << m_name << " has become alive !" << std::endl;
}

FragTrap::FragTrap(const FragTrap &o) :
	ClapTrap(o)
{
	std::cout << "FragTrap " << m_name << " has become alive !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << m_name << " ceased to exist !" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (!canDoAction(std::string("attack ") + target))
		return ;
	--m_ep;
	std::cout
		<< "FragTrap " << m_name << " attacks " << target
		<< ", causing " << m_ad << " points of damage !"
		<< std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	if (!canDoAction("go into gate keeper mode"))
		return ;
	std::cout
		<< "FragTrap " << m_name
		<< " requests a high fives with you guys !."
		<< std::endl;
}
