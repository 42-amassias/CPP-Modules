#include "WrongCat.hpp"

WrongCat::WrongCat() :
	WrongAnimal("WrongCat")
{
	std::cout << "new wrong cat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &o) :
	WrongAnimal(o)
{
	std::cout << "new wrong cat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "killed wrong cat" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*wrong cat sound*" << std::endl;
}