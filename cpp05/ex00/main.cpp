#include "Bureaucrat.hpp"

#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat	a("Alex", Bureaucrat::highest_grade - 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	a("Bob", Bureaucrat::lowest_grade + 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	b("Chloe", Bureaucrat::highest_grade);

		std::cout << b << std::endl;
		b.downgrade();
		std::cout << b << std::endl;
		b.upgrade();
		std::cout << b << std::endl;
		b.upgrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	b("Dan", Bureaucrat::lowest_grade);

		std::cout << b << std::endl;
		b.upgrade();
		std::cout << b << std::endl;
		b.downgrade();
		std::cout << b << std::endl;
		b.downgrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
