#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("presidential pardon form", 25, 5),
	m_target("Unknown target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("presidential pardon form", 25, 5),
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
