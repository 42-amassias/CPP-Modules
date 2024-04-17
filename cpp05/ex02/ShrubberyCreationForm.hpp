#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm :
	public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &o);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &o);

		void					execute(const Bureaucrat &executor) const;

	private:
		ShrubberyCreationForm(void);

	private:
		std::string	m_target;
};