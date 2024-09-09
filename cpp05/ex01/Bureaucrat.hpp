#pragma once

#include "Form.hpp"

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const Bureaucrat &o);
		~Bureaucrat();

		Bureaucrat(const std::string &name, const unsigned int grade);

		Bureaucrat			&operator=(const Bureaucrat &o);

		void				upgrade(const unsigned int amount);
		void				upgrade(void);
		void				downgrade(const unsigned int amount);
		void				downgrade(void);

		void				signForm(Form &form) const;

		const std::string	&getName(void) const;
		unsigned int		getGrade(void) const;

	private:
		Bureaucrat(void);

	public:
		static const unsigned int	highest_grade = 1;
		static const unsigned int	lowest_grade = 150;

	private:
		const std::string	m_name;
		unsigned int		m_grade;

	public:
		class GradeTooHighException :
			public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException :
			public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);
