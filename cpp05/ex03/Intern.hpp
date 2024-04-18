#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &o);
		~Intern(void);

		Intern			&operator=(const Intern &o);

		AForm			*makeForm(const std::string &form_name, const std::string &target) const;
	
	private:
		typedef AForm	*(*form_creator_t)(const std::string &);

		typedef struct
		{
			const std::string	&name;
			form_creator_t		creator;
		}	form_t;

		static AForm	*createShrubberyCreationForm(const std::string &target);
		static AForm	*createRobotomyRequestForm(const std::string &target);
		static AForm	*createPresidentialPardonForm(const std::string &target);
};