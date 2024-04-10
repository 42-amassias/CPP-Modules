#pragma once

#include "AMateria.hpp"

#include <iostream>

class Character :
	public ICharacter
{
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &o);
		~Character(void);
		
		Character	&operator=(const Character &o);

		virtual const std::string	&getName(void) const;
		virtual void				equip(AMateria *materia);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);

	public:
		static const size_t	inventory_slot_count = 4;

	private:
		std::string	m_name;
		AMateria	*m_materias[Character::inventory_slot_count];
};
