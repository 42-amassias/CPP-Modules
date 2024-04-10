#include "Character.hpp"

Character::Character(void)
{
	for (size_t i = 0; i < Character::inventory_slot_count; ++i)
		m_materias[i] = NULL;
}

Character::Character(const std::string &name) :
	m_name(name)
{
	for (size_t i = 0; i < Character::inventory_slot_count; ++i)
		m_materias[i] = NULL;
}

Character::Character(const Character &o)
{
	for (size_t i = 0; i < Character::inventory_slot_count; ++i)
		m_materias[i] = NULL;
	*this = o;
}

Character::~Character()
{
	for (size_t i = 0; i < Character::inventory_slot_count; ++i)
		if (m_materias[i] != NULL)
			delete m_materias[i];
}

Character	&Character::operator=(const Character &o)
{
	if (this == &o)
		return (*this);
	m_name = o.m_name;
	for (size_t i = 0; i < Character::inventory_slot_count; ++i)
	{
		if (m_materias[i])
			delete m_materias[i];
		m_materias[i] = o.m_materias[i] == NULL
			? NULL
			: o.m_materias[i]->clone();
	}
	return (*this);
}

const std::string	&Character::getName() const
{
	return (m_name);
}

void	Character::equip(AMateria *materia)
{
	if (materia == NULL)
		return ;
	for (size_t i = 0; i < Character::inventory_slot_count; ++i)
		if (m_materias[i] == NULL)
		{
			m_materias[i] = materia;
			return ;
		}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || (size_t)idx >= Character::inventory_slot_count)
		return ;
	if (m_materias[idx] != NULL)
		delete m_materias[idx];
	m_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	AMateria	*materia = m_materias[idx];

	if (materia == NULL)
		return ;
	materia->use(target);
}
