#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() :
	m_contact_count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void			PhoneBook::add(const Contact &contact)
{
	for (size_t i = 0; i < PhoneBook::max_contact_count - 1; ++i)
		m_contacts[i + 1] = m_contacts[i];
	m_contacts[0] = contact;
	if (m_contact_count < PhoneBook::max_contact_count)
		++m_contact_count;
}

static void	_display_field(const std::string &field)
{
	std::string	tmp;

	tmp = field;
	if (tmp.length() > 10)
		tmp = tmp.substr(0, 9) + ".";
	std::cout << std::left << std::setw(10) << tmp;
}

void	PhoneBook::display(void) const
{
	static std::string	padding(10, '-');
	std::string			tmp;

	std::cout << std::left << std::setw(10) << "Index"
		<< " | " << std::left << std::setw(10) << "First name"
		<< " | " << std::left << std::setw(10) << "Last name"
		<< " | " << std::left << std::setw(10) << "Nickname"
		<< std::endl;
	std::cout << padding << "-|-" << padding << "-|-" << padding << "-|-" << padding << std::endl;
	for (size_t i = 0; i < m_contact_count; ++i)
	{
		std::cout << std::left << std::setw(10) << i << " | ";
		_display_field(m_contacts[i].get_first_name());
		std::cout << " | ";
		_display_field(m_contacts[i].get_last_name());
		std::cout << " | ";
		_display_field(m_contacts[i].get_nickname());
		std::cout << std::endl;
	}
}

size_t	PhoneBook::get_contact_count(void) const
{
	return (m_contact_count);
}

const Contact	&PhoneBook::get(size_t i) const
{
	if (i >= m_contact_count)
		throw std::runtime_error("Index out of bounds.");
	return (m_contacts[i]);
}
