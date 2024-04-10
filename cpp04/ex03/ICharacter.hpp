#pragma once

#include "AMateria.hpp"

#include <iostream>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter(void) {};
		virtual const std::string	&getName(void) const = 0;
		virtual void				equip(AMateria *materia) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;
};
