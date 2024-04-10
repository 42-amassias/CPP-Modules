#pragma once

#include "AMateria.hpp"

class Cure :
	public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &o);
		~Cure(void);

		Cure	&operator=(const Cure &o);

		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);
};
