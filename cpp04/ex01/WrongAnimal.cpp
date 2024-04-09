#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
	m_type("")
{
	std::cout << "new animal" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) :
	m_type(type)
{
	std::cout << "new wrong animal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &o) :
	m_type(o.m_type)
{
	std::cout << "new wrong animal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "killed wrong animal" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &o)
{
	m_type = o.m_type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*wrong animal sound*" << std::endl;
}

const std::string	&WrongAnimal::getType(void) const
{
	return (m_type);
}
