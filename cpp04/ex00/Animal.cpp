#include "Animal.hpp"

Animal::Animal() :
	m_type("")
{
	std::cout << "new animal" << std::endl;
}

Animal::Animal(const std::string &type) :
	m_type(type)
{
	std::cout << "new animal" << std::endl;
}

Animal::Animal(const Animal &o)
{
	*this= o;
	std::cout << "new animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "killed animal" << std::endl;
}

Animal	&Animal::operator=(const Animal &o)
{
	if (this == &o)
		return (*this);
	m_type = o.m_type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "*animal sound*" << std::endl;
}

const std::string	&Animal::getType(void) const
{
	return (m_type);
}
