#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &o);
		~Bureaucrat();

		Bureaucrat(const std::string &name, const unsigned int grade);

		Bureaucrat			&operator=(const Bureaucrat &o);

		void				upgrade(const unsigned int amount);
		void				upgrade(void);
		void				downgrade(const unsigned int amount);
		void				downgrade(void);

		const std::string	&getName(void) const;
		unsigned int		getGrade(void) const;

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
		} gradeTooHighException;

		class GradeTooLowException :
			public std::exception
		{
			virtual const char*	what() const throw();
		} gradeTooLowException;
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);
