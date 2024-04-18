#pragma once

#include "AForm.hpp"

class PresidentialPardonForm :
	public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &o);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &o);

		void					execute(const Bureaucrat &executor) const;

	private:
		PresidentialPardonForm(void);

	public:
		static const AForm::grade_t	sign_grade;
		static const AForm::grade_t	execute_grade;
		static const std::string	litteral_name;

	private:
		std::string	m_target;
};