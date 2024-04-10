#include "Cure.hpp"

Cure::Cure(void) :
	AMateria("cure")
{
}

Cure::Cure(const Cure &o) :
	AMateria("cure")
{
	(void)o;
}

Cure::~Cure(void)
{
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout
		<< "* heals " << target.getName() << "'s wounds *"
		<< std::endl;
}

Cure	&Cure::operator=(const Cure &o)
{
	(void)o;
	return (*this);
}