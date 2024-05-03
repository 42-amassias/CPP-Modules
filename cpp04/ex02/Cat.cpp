#include "Cat.hpp"

Cat::Cat(void) :
	Animal("Cat")
{
	m_brain = new Brain();
	std::cout << "new cat" << std::endl;
}

Cat::Cat(const Cat &o) :
	Animal(o),
	m_brain(NULL)
{
	*this = o;
	std::cout << "new cat" << std::endl;
}

Cat::~Cat(void)
{
	delete m_brain;
	std::cout << "killed cat" << std::endl;
}

Cat		&Cat::operator=(const Cat &o)
{
	if (this == &o)
		return (*this);
	Animal::operator=(o);
	if (m_brain != NULL)
		delete m_brain;
	m_brain = new Brain(*o.m_brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "*cat sound*" << std::endl;
}