#include "RobotomyRequestForm.hpp"

#include <cstdlib>

const AForm::grade_t	RobotomyRequestForm::sign_grade = 72;
const AForm::grade_t	RobotomyRequestForm::execute_grade = 75;
const std::string		RobotomyRequestForm::litteral_name = "robotomy request";

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm(
		RobotomyRequestForm::litteral_name,
		RobotomyRequestForm::sign_grade,
		RobotomyRequestForm::execute_grade),
	m_target("Unknown target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm(
		RobotomyRequestForm::litteral_name,
		RobotomyRequestForm::sign_grade,
		RobotomyRequestForm::execute_grade
		),
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
