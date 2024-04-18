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

	public:
		static const AForm::grade_t	sign_grade;
		static const AForm::grade_t	execute_grade;
		static const std::string	litteral_name;

	private:
		std::string	m_target;
};