#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {};
		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
};
