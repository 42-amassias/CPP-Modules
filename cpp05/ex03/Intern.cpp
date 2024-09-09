#include "Intern.hpp"

#define MAKE_FORM_DESCRIPTOR(name)	\
	{								\
		name::litteral_name,		\
		Intern::create##name		\
	}

Intern::Intern(void)
{
}

Intern::Intern(const Intern &o)
{
	*this = o;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(const Intern &o)
{
	(void) o;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &form_name, const std::string &target) const
{
	static Intern::form_t	forms[] = {
		MAKE_FORM_DESCRIPTOR(ShrubberyCreationForm),
		MAKE_FORM_DESCRIPTOR(RobotomyRequestForm),
		MAKE_FORM_DESCRIPTOR(PresidentialPardonForm),
	};

	for (size_t i = 0; i < sizeof(forms) / sizeof(Intern::form_t); ++i)
		if (form_name == forms[i].name)
		{
			std::cout
				<< "Intern creates form "
				<< form_name
				<< "."
				<< std::endl;
			return (forms[i].creator(target));
		}
	std::cout
		<< "Intern could not create form "
		<< form_name
		<< ": form does not exist."
		<< std::endl;
	return (NULL);
}

AForm	*Intern::createShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
