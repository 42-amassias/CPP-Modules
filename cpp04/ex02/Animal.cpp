#include "Animal.hpp"

Animal::Animal(void) :
	m_type("Animal")
{
	std::cout << "new animal" << std::endl;
}

Animal::Animal(const std::string &type) :
	m_type(type)
{
	std::cout << "new animal" << std::endl;
}

Animal::Animal(const Animal &o) :
	m_type(o.m_type)
{
	*this = o;
	std::cout << "new animal" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "killed animal" << std::endl;
}

Animal	&Animal::operator=(const Animal &o)
{
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
