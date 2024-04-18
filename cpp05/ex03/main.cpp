#include "Intern.hpp"

#include <iostream>

void	test_form(AForm *form)
{
	if (form == NULL)
		std::cout << "form is null" << std::endl;
	else
	{
		std::cout << *form << std::endl;
		delete form;
	}
}

int	main(void)
{
	Intern	intern;

	test_form(intern.makeForm("unknown form", "target"));
	test_form(intern.makeForm(ShrubberyCreationForm::litteral_name, "target"));
	test_form(intern.makeForm(RobotomyRequestForm::litteral_name, "target"));
	test_form(intern.makeForm(PresidentialPardonForm::litteral_name, "target"));
}
