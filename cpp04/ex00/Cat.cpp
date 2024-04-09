#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
	std::cout << "new cat" << std::endl;
}

Cat::Cat(const Cat &o) :
	Animal(o)
{
	std::cout << "new cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "killed cat" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "*cat sound*" << std::endl;
}