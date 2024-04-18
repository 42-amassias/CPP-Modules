#pragma once

#include "AForm.hpp"

class RobotomyRequestForm :
	public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &o);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &o);

		void				execute(const Bureaucrat &executor) const;

	private:
		RobotomyRequestForm(void);

	public:
		static const AForm::grade_t	sign_grade;
		static const AForm::grade_t	execute_grade;
		static const std::string	litteral_name;

	private:
		std::string	m_target;
};
