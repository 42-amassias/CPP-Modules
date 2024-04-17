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

	private:
		std::string	m_target;
};