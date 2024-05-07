#include "Ice.hpp"

Ice::Ice(void) :
	AMateria("ice")
{
}

Ice::Ice(const Ice &o) :
	AMateria("ice")
{
	*this = o;
}

Ice::~Ice(void)
{
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout
		<< "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
}

Ice	&Ice::operator=(const Ice &o)
{
	(void)o;
	return (*this);
}
