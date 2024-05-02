#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const& name) :
	ClapTrap(name)
{
	m_hp = 100;
	m_ep = 50;
	m_ad = 20;
	std::cout << "FragTrap " << m_name << " has become alive !" << std::endl;
}

FragTrap::FragTrap(const FragTrap &o) :
	ClapTrap(o)
{
	*this = o;
	std::cout << "FragTrap " << m_name << " has become alive !" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << m_name << " ceased to exist !" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const& o)
{
	if (this == &o)
		return (*this);
	ClapTrap::operator=(o);
	return (*this);
}

void	FragTrap::attack(std::string const& target)
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
