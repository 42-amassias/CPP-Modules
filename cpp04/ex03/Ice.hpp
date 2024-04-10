#pragma once

#include "AMateria.hpp"

class Ice :
	public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &o);
		~Ice(void);

		Ice	&operator=(const Ice &o);

		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);
};
