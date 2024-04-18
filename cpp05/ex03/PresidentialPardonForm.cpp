#include "PresidentialPardonForm.hpp"

const AForm::grade_t	PresidentialPardonForm::sign_grade = 25;
const AForm::grade_t	PresidentialPardonForm::execute_grade = 5;
const std::string		PresidentialPardonForm::litteral_name = "presidential pardon";

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm(
		PresidentialPardonForm::litteral_name,
		PresidentialPardonForm::sign_grade,
		PresidentialPardonForm::execute_grade),
	m_target("Unknown target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm(
		PresidentialPardonForm::litteral_name,
		PresidentialPardonForm::sign_grade,
		PresidentialPardonForm::execute_grade),
	m_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &o) :
	AForm(o),
	m_target(o.m_target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm & o)
{
	if (this == &o)
		return (*this);
	AForm::operator=(o);
	m_target = o.m_target;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkIfCanExecute(executor);
	std::cout
		<< m_target
		<< " has been pardoned by Zaphod Beeblebrox"
		<< std::endl;
}
