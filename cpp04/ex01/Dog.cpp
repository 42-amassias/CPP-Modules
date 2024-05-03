#include "Dog.hpp"

Dog::Dog(void) :
	Animal("Dog")
{
	m_brain = new Brain();
	std::cout << "new dog" << std::endl;
}

Dog::Dog(const Dog &o) :
	Animal(o),
	m_brain(NULL)
{
	*this = o;
	std::cout << "new dog" << std::endl;
}

Dog::~Dog(void)
{
	delete m_brain;
	std::cout << "killed dog" << std::endl;
}

Dog		&Dog::operator=(const Dog &o)
{
	if (this == &o)
		return (*this);
	Animal::operator=(o);
	if (m_brain != NULL)
		delete m_brain;
	m_brain = new Brain(*o.m_brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "*dog sound*" << std::endl;
}