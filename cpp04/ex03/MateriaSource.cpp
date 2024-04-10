#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (size_t i = 0; i < MateriaSource::slot_count; ++i)
		m_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &o)
{
	for (size_t i = 0; i < MateriaSource::slot_count; ++i)
		m_materias[i] = NULL;
	*this = o;
}

MateriaSource::~MateriaSource(void)
{
	for (size_t i = 0; i < MateriaSource::slot_count; ++i)
		if (m_materias[i] != NULL)
			delete m_materias[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &o)
{
	if (this == &o)
		return (*this);
	for (size_t i = 0; i < MateriaSource::slot_count; ++i)
	{
		if (m_materias[i] != NULL)
			delete m_materias[i];
		m_materias[i] = o.m_materias[i] == NULL
			? NULL
			: o.m_materias[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL)
		return ;
	for (size_t i = 0; i < MateriaSource::slot_count; ++i)
		if (m_materias[i] == NULL)
		{
			m_materias[i] = materia;
			return ;
		}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (size_t i = 0; i < MateriaSource::slot_count; ++i)
		if (m_materias[i]->getType() == type)
			return (m_materias[i]->clone());
	return (NULL);
}
