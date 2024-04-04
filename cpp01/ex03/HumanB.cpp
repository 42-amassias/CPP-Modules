#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon) :
	m_name(name),
	m_weapon(weapon)
{
}

HumanB::HumanB(std::string name) :
	m_name(name),
	m_weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (m_weapon)
		std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
	else
		std::cout << m_name << " attacks with their bare hands" << std::endl;
}
