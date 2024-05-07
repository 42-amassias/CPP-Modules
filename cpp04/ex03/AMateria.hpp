#pragma once

#include "ICharacter.hpp"

#include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &o);
		virtual ~AMateria(void);

		const std::string	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	private:
		std::string	m_type;
};
