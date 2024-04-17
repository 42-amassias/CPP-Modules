#include "AForm.hpp"

AForm::AForm(void) :
	m_name("Unknown form"),
	m_signed(false),
	m_sign_grade(0),
	m_execute_grade(0)
{
}

AForm::AForm(const AForm &o) :
	m_name(o.m_name),
	m_sign_grade(o.m_sign_grade),
	m_execute_grade(o.m_execute_grade)
{
	*this = o;
}

AForm::~AForm(void)
{
}

AForm::AForm(
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
		throw AForm::GradeTooHighException();
	if (m_sign_grade > Bureaucrat::lowest_grade)
		throw AForm::GradeTooLowException();
}

AForm	&AForm::operator=(const AForm &o)
{
	if (this == &o)
		return (*this);
	m_signed = o.m_signed;
	return (*this);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	checkIfCanSign(bureaucrat);
	m_signed = true;
}

const std::string	&AForm::getName(void) const
{
	return (m_name);
}

bool	AForm::isSigned(void) const
{
	return (m_signed);
}

unsigned int	AForm::getSignGrade(void) const
{
	return (m_sign_grade);
}

unsigned int	AForm::getExecuteGrade(void) const
{
	return (m_execute_grade);
}

void	AForm::checkIfCanSign(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > m_sign_grade)
		throw AForm::GradeTooLowException();
}

void	AForm::checkIfCanExecute(const Bureaucrat &bureaucrat) const
{
	if (!m_signed)
		throw AForm::FormNotSignedException();
	if (bureaucrat.getGrade() > m_execute_grade)
		throw AForm::GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form was not signed");
}

std::ostream	&operator<<(std::ostream &stream, const AForm &form)
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
