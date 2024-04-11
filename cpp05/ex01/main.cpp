#include "Bureaucrat.hpp"

#include <iostream>

int	main(void)
{
	std::cout << "Test #1" << std::endl;
	try
	{
		Form	f("form", Bureaucrat::highest_grade - 1, Bureaucrat::highest_grade + 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Test #2" << std::endl;
	try
	{
		Form	f("form", Bureaucrat::highest_grade, Bureaucrat::highest_grade + 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Test #3" << std::endl;
	try
	{
		Form	f("form", Bureaucrat::lowest_grade + 1, Bureaucrat::lowest_grade);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Test #4" << std::endl;
	try
	{
		Form	f("form", Bureaucrat::lowest_grade, Bureaucrat::highest_grade);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Test #5" << std::endl;
	try
	{
		Bureaucrat	b("bob", 12);
		Form		f3("form 3", 13, 10);
		Form		f2("form 2", 12, 10);
		Form		f1("form 1", 11, 10);

		std::cout << b << " :: " << f3 << std::endl;
		b.signForm(f3);
		std::cout << b << " :: " << f3 << std::endl;
		b.signForm(f2);
		std::cout << b << " :: " << f3 << std::endl;
		b.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Test #6" << std::endl;
	try
	{
		Bureaucrat	b("bob", 12);
		Form		f3("form 3", 13, 10);
		Form		f2("form 2", 12, 10);
		Form		f1("form 1", 11, 10);

		std::cout << b << " :: " << f3 << std::endl;
		f3.beSigned(b);
		std::cout << b << " :: " << f2 << std::endl;
		f2.beSigned(b);
		std::cout << b << " :: " << f1 << std::endl;
		f1.beSigned(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
