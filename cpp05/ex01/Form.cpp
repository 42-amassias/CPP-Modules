#include "Form.hpp"

Form::Form(void) :
	m_name("Unknown form"),
	m_signed(false),
	m_sign_grade(0),
	m_execute_grade(0)
{
}

Form::Form(const Form &o) :
	m_name(o.m_name),
	m_sign_grade(o.m_sign_grade),
	m_execute_grade(o.m_execute_grade)
{
	*this = o;
}

Form::~Form(void)
{
}

Form::Form(
	const std::string &name,
	unsigned int sign_grade,
	unsigned int execute_grade
	) :
	m_name(name),
	m_signed(false),
	m_sign_grade(sign_grade),
	m_execute_grade(execute_grade)
{
	if (m_sign_grade < Bureaucrat::highest_grade)
		throw Form::GradeTooHighException();
	if (m_sign_grade > Bureaucrat::lowest_grade)
		throw Form::GradeTooLowException();
}

Form	&Form::operator=(const Form &o)
{
	if (this == &o)
		return (*this);
	m_signed = o.m_signed;
	return (*this);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > m_sign_grade)
		throw Form::GradeTooLowException();
	m_signed = true;
}

const std::string	&Form::getName(void) const
{
	return (m_name);
}

bool	Form::isSigned(void) const
{
	return (m_signed);
}

unsigned int	Form::getSignGrade(void) const
{
	return (m_sign_grade);
}

unsigned int	Form::getExecuteGrade(void) const
{
	return (m_execute_grade);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &stream, const Form &form)
{
	stream
		<< form.getName()
		<< ", sign grade "
		<< form.getSignGrade()
		<< ", execute grade "
		<< form.getExecuteGrade()
		<< ", "
		<< (form.isSigned() ? "signed" : "not signed");
	return (stream);
}
