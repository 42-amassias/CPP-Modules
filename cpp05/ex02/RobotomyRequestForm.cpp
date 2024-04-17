#include "RobotomyRequestForm.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("robotomy request form", 72, 45),
	m_target("Unknown target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("shrubbery creation form", 75, 45),
	m_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o) :
	AForm(o),
	m_target(o.m_target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm & o)
{
	if (this == &o)
		return (*this);
	AForm::operator=(o);
	m_target = o.m_target;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	checkIfCanExecute(executor);
	std::cout
		<< m_target
		<< " "
		<< (std::rand() % 2
			? "has been robotomized successfully"
			: "has not been robotomized")
		<< std::endl;
}
