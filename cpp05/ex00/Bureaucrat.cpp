#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	m_name("unknown bureaucrat"),
	m_grade(Bureaucrat::lowest_grade)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &o)
{
	*this = o;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int grade) :
	m_name(name),
	m_grade(grade)
{
	if (m_grade < Bureaucrat::highest_grade)
		throw Bureaucrat::GradeTooHighException();
	if (m_grade > Bureaucrat::lowest_grade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &o)
{
	if (this == &o)
		return (*this);
	m_grade = o.m_grade;
	return (*this);
}

void	Bureaucrat::upgrade(unsigned int amount)
{
	if (m_grade < Bureaucrat::highest_grade + amount)
		throw Bureaucrat::GradeTooHighException();
	m_grade -= amount;
}

void	Bureaucrat::upgrade(void)
{
	upgrade(1);
}


void	Bureaucrat::downgrade(unsigned int amount)
{
	if (m_grade + amount > Bureaucrat::lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	m_grade += amount;
}

void	Bureaucrat::downgrade(void)
{
	downgrade(1);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (m_name);
}

unsigned int		Bureaucrat::getGrade(void) const
{
	return (m_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream
		<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< ".";
	return (stream);
}
