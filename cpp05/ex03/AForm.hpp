#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	public:
		typedef unsigned int	grade_t;

	public:
		AForm(const AForm &o);
		virtual ~AForm(void);

		AForm(const std::string &name, grade_t sign_grade, grade_t execute_grade);

		AForm	&operator=(const AForm &o);

		void	beSigned(const Bureaucrat &bureaucrat);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		grade_t				getSignGrade(void) const;
		grade_t				getExecuteGrade(void) const;

		virtual void		execute(const Bureaucrat &executor) const = 0;

	protected:
		void				checkIfCanSign(const Bureaucrat &bureaucrat) const;
		void				checkIfCanExecute(const Bureaucrat &bureaucrat) const;

	private:
		AForm(void);

	private:
		const std::string	m_name;
		bool				m_signed;
		const grade_t		m_sign_grade;
		const grade_t		m_execute_grade;

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
