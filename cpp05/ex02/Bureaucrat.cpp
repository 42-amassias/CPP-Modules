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
	m_name = o.m_name;
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

void	_log(
			const Bureaucrat &bureaucrat,
			const AForm &form,
			const std::string &msg
			)
{
	std::cout
		<< bureaucrat.getName()
		<< " could not sign "
		<< form.getName()
		<< " because "
		<< msg
		<< "."
		<< std::endl;
}

void	Bureaucrat::signAForm(AForm &form) const
{
	if (form.isSigned())
	{
		_log(*this, form, "is is already signed");
		return ;
	}
	if (form.getSignGrade() < m_grade)
	{
		_log(*this, form, "his grade isn't high enough");
		return ;
	}
	form.beSigned(*this);
	std::cout
		<< m_name
		<< " signed "
		<< form.getName()
		<< std::endl;
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout
			<< m_name
			<< " executed "
			<< form.getName()
			<< std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout
			<< form.getName()
			<< " is not yet signed"
			<< std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout
			<< m_name
			<< " does not have the required grade to execute "
			<< form.getName()
			<< " (required "
			<< form.getExecuteGrade()
			<< ", actual "
			<< m_grade
			<< ")"
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout
			<< "Could not execute "
			<< form.getName()
			<< " because of an unexpected exception"
			<< std::endl;
	}
}

const std::string	&Bureaucrat::getName(void) const
{
	return (m_name);
}

unsigned int	Bureaucrat::getGrade(void) const
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
