#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) :
	m_type(type)
{
}

AMateria::AMateria(const AMateria &o)
{
	*this = o;
}

AMateria::~AMateria(void)
{
}

const std::string	&AMateria::getType(void) const
{
	return (m_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout
		<< "* Using " << m_type << " materia on " << target.getName() << " *"
		<< std::endl;
}