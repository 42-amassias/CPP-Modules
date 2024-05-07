#include "Cat.hpp"

Cat::Cat(void) :
	Animal("Cat")
{
	std::cout << "new cat" << std::endl;
}

Cat::Cat(const Cat &o) :
	Animal(o)
{
	Animal::operator=(o);
	std::cout << "new cat" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "killed cat" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "*cat sound*" << std::endl;
}