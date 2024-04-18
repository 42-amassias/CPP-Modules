#pragma once

#include "AForm.hpp"

#include <iostream>
#include <exception>

class AForm;

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

		void				signAForm(AForm &form) const;
		void				executeForm(const AForm &form) const;

		const std::string	&getName(void) const;
		unsigned int		getGrade(void) const;

	private:
		Bureaucrat(void);

	public:
		static const unsigned int	highest_grade = 1;
		static const unsigned int	lowest_grade = 150;

	private:
		std::string		m_name;
		unsigned int	m_grade;

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
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);
