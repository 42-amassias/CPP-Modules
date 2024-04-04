#include "PhoneBook.hpp"

#include <iostream>

static std::string	_get_field(const std::string &field_name)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << field_name << ": ";
		std::getline(std::cin, input);
	}
	return (input);
}

int	main(void)
{
	PhoneBook	phone_book;
	Contact		contact;
	std::string	input;
	size_t		index;

	while (true)
	{
		input = "";
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "")
		{
			std::cout << std::endl;
			break ;
		}
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			contact.set_first_name(_get_field("First name"));
			contact.set_last_name(_get_field("Last name"));
			contact.set_nickname(_get_field("Nickname"));
			contact.set_phone_number(_get_field("Phone number"));
			contact.set_darkest_secret(_get_field("Darkest secret"));
			phone_book.add(contact);
		} else if (input == "SEARCH")
		{
			if (phone_book.get_contact_count() == 0)
			{
				std::cout << "No contact registered yet." << std::endl;
				continue ;
			}
			phone_book.display();
			std::cout << "Select contact index: ";
			std::cin >> index;
			if (index < phone_book.get_contact_count())
				phone_book.get(index).display();
			else
				std::cout << "Invalid index" << std::endl;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}