#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource :
	public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &o);
		~MateriaSource(void);

		MateriaSource	&operator=(const MateriaSource &o);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria	*createMateria(const std::string &type);
	
	public:
		static const size_t	slot_count = 4;

	private:
		AMateria	*m_materias[MateriaSource::slot_count];
};
