#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& name) :
	m_name(name),
	m_hp(10),
	m_ep(10),
	m_ad(0)
{
	std::cout << m_name << " has become alive !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& o) :
	m_name(o.m_name),
	m_hp(o.m_hp),
	m_ep(o.m_ep),
	m_ad(o.m_ad)
{
	std::cout << m_name << " has become alive !" << std::endl;
}
ClapTrap::~ClapTrap(void)
{
	std::cout << m_name << " ceased to exist !" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& o)
{
	if (this == &o)
		return (*this);
	this->m_name = o.m_name;
	this->m_hp = o.m_hp;
	this->m_ep = o.m_ep;
	this->m_ad = o.m_ad;
	return (*this);
}

bool	ClapTrap::canDoAction(std::string const& action) const
{
	if (m_hp > 0 && m_ep > 0)
		return (true);
	std::cout
		<< "ClapTrap " << m_name
		<< " could not " << action
		<< " because " << m_name << " is "
		<< (m_hp == 0 ? "dead." : "exhausted.")
		<< std::endl;
	return (false);
}

void	ClapTrap::attack(std::string const& target)
{
	if (!canDoAction(std::string("attack ") + target))
		return ;
	--m_ep;
	std::cout
		<< "ClapTrap " << m_name << " attacks " << target
		<< ", causing " << m_ad << " points of damage !"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int const amount)
{
	m_hp = amount > m_hp ? 0 :  m_hp - amount;
	std::cout
		<< "ClapTrap " << m_name << " took " << amount
		<< " points of damage. ";
	if (m_hp)
		std::cout << "It now has " << m_hp << " hit points.";
	else
		std::cout << m_name << " is dead.";
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int const amount)
{
	if (!canDoAction("be repaired"))
		return ;
	m_hp += amount;
	--m_ep;
	std::cout
		<< "ClapTrap " << m_name << " is repaired."
		<< "It gained " << amount << " hit points for a total of " << m_hp
		<< "hit points !"
		<< std::endl;
}
