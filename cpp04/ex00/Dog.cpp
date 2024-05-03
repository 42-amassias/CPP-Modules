#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	std::cout << "new dog" << std::endl;
}

Dog::Dog(const Dog &o) :
	Animal(o)
{
	Animal::operator=(o);
	std::cout << "new dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "killed dog" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "*dog sound*" << std::endl;
}