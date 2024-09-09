#include "WrongCat.hpp"

WrongCat::WrongCat(void) :
	WrongAnimal("WrongCat")
{
	std::cout << "new wrong cat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &o) :
	WrongAnimal(o)
{
	*this = o;
	std::cout << "new wrong cat" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "killed wrong cat" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &o)
{
	WrongAnimal::operator=(o);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*wrong cat sound*" << std::endl;
}