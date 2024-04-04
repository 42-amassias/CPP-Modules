#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name, Weapon *weapon);
		HumanB(std::string name);
		~HumanB(void);

		void	setWeapon(Weapon &weapon);
		void	attack(void) const;
	private:
		std::string	m_name;
		Weapon		*m_weapon;
};

#endif