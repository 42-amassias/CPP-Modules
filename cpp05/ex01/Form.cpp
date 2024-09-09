#include "Form.hpp"

Form::Form(void) :
	m_name("Unknown form"),
	m_sign_grade(0),
	m_execute_grade(0),
	m_signed(false)
{
}

Form::Form(const Form &o) :
	m_name(o.m_name),
	m_sign_grade(o.m_sign_grade),
	m_execute_grade(o.m_execute_grade),
	m_signed(false)
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
	m_sign_grade(sign_grade),
	m_execute_grade(execute_grade),
	m_signed(false)
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

void	Form::log_sign_failure(
			const Bureaucrat &bureaucrat,
			const std::string &msg
			) const
{
	std::cout
		<< bureaucrat.getName()
		<< " could not sign "
		<< m_name
		<< " because "
		<< msg
		<< "."
		<< std::endl;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (m_signed)
	{
		log_sign_failure(bureaucrat, "is is already signed");
		return ;
	}
	if (m_sign_grade < bureaucrat.getGrade())
	{
		log_sign_failure(bureaucrat, "his grade isn't high enough");
		throw Form::GradeTooLowException();
	}
	m_signed = true;
	std::cout
		<< bureaucrat.getName()
		<< " signed "
		<< m_name
		<< std::endl;
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
