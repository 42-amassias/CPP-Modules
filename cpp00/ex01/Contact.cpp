#include "Contact.hpp"

#include <iostream>
#include <iomanip>

Contact::Contact() :
	m_first_name(),
	m_last_name(),
	m_nickname(),
	m_phone_number(),
	m_darkest_secret()
{
}

Contact::~Contact()
{
}

Contact&	Contact::operator=(const Contact& o)
{
	if (this == &o)
		return (*this);
	m_first_name = o.m_first_name;
	m_last_name = o.m_last_name;
	m_nickname = o.m_nickname;
	m_phone_number = o.m_phone_number;
	m_darkest_secret = o.m_darkest_secret;
	return (*this);
}

void	Contact::set_first_name(const std::string &first_name)
{
	m_first_name = first_name;
}

void	Contact::set_last_name(const std::string &last_name)
{
	m_last_name = last_name;
}

void	Contact::set_nickname(const std::string &nickname)
{
	m_nickname = nickname;
}

void	Contact::set_phone_number(const std::string &phone_number)
{
	m_phone_number = phone_number;
}

void	Contact::set_darkest_secret(const std::string &darkest_secret)
{
	m_darkest_secret = darkest_secret;
}

const std::string	&Contact::get_first_name(void) const
{
	return (m_first_name);
}

const std::string	&Contact::get_last_name(void) const
{
	return (m_last_name);
}

const std::string	&Contact::get_nickname(void) const
{
	return (m_nickname);
}

const std::string	&Contact::get_phone_number(void) const
{
	return (m_phone_number);
}

const std::string	&Contact::get_darkest_secret(void) const
{
	return (m_darkest_secret);
}


void	Contact::display() const
{
	size_t	max_width(sizeof("Value") - 1);

	if (m_first_name.length() > max_width)
		max_width = m_first_name.length();
	if (m_last_name.length() > max_width)
		max_width = m_last_name.length();
	if (m_nickname.length() > max_width)
		max_width = m_nickname.length();
	if (m_phone_number.length() > max_width)
		max_width = m_phone_number.length();
	if (m_darkest_secret.length() > max_width)
		max_width = m_darkest_secret.length();
	std::cout << std::left << std::setw(14) << "Field" << " | " << std::left << std::setw(max_width) << "Value" << std::endl;
	std::cout << std::left << std::string(14, '-')  << "-|-" << std::string(max_width, '-') << std::endl;
	std::cout << std::left << std::setw(14) << "First name" << " | " << std::left << std::setw(max_width) << m_first_name << std::endl;
	std::cout << std::left << std::setw(14) << "Last name" << " | " << std::left << std::setw(max_width) << m_last_name << std::endl;
	std::cout << std::left << std::setw(14) << "Nickname" << " | " << std::left << std::setw(max_width) << m_nickname << std::endl;
	std::cout << std::left << std::setw(14) << "Phone number" << " | " << std::left << std::setw(max_width) << m_phone_number << std::endl;
	std::cout << std::left << std::setw(14) << "Darkest secret" << " | "<< std::left << std::setw(max_width) << m_darkest_secret << std::endl;
}
