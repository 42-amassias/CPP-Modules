#include "AForm.hpp"

AForm::AForm(void) :
	m_name("Unknown form"),
	m_sign_grade(0),
	m_execute_grade(0),
	m_signed(false)
{
}

AForm::AForm(const AForm &o) :
	m_name(o.m_name),
	m_sign_grade(o.m_sign_grade),
	m_execute_grade(o.m_execute_grade),
	m_signed(false)
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
	m_sign_grade(sign_grade),
	m_execute_grade(execute_grade),
	m_signed(false)
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

void	AForm::log_sign_failure(
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

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (!checkIfCanSign(bureaucrat))
		return ;
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

bool	AForm::checkIfCanSign(const Bureaucrat &bureaucrat) const
{
	if (m_signed)
	{
		log_sign_failure(bureaucrat, "is is already signed");
		return (false);
	}
	if (m_sign_grade < bureaucrat.getGrade())
	{
		log_sign_failure(bureaucrat, "his grade isn't high enough");
		throw AForm::GradeTooLowException();
	}
	return (true);
}

bool	AForm::checkIfCanExecute(const Bureaucrat &bureaucrat) const
{
	if (!m_signed)
		throw AForm::FormNotSignedException();
	if (bureaucrat.getGrade() > m_execute_grade)
		throw AForm::GradeTooLowException();
	return (true);
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
