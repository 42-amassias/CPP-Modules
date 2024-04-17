#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		AForm(const AForm &o);
		virtual ~AForm(void);

		AForm(const std::string &name, unsigned int sign_grade, unsigned int execute_grade);

		AForm	&operator=(const AForm &o);

		void	beSigned(const Bureaucrat &bureaucrat);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecuteGrade(void) const;

		virtual void		execute(const Bureaucrat &executor) const = 0;

	protected:
		void				checkIfCanSign(const Bureaucrat &bureaucrat) const;
		void				checkIfCanExecute(const Bureaucrat &bureaucrat) const;

	private:
		AForm(void);

	private:
		const std::string	m_name;
		bool				m_signed;
		const unsigned int	m_sign_grade;
		const unsigned int	m_execute_grade;

	public:
		class GradeTooHighException :
			public std::exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooLowException :
			public std::exception
		{
			virtual const char*	what() const throw();
		};

		class FormNotSignedException :
			public std::exception
		{
			virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &form);
