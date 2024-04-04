#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();

		Contact&			operator=(const Contact& o);

		void				set_first_name(const std::string &first_name);
		void				set_last_name(const std::string &last_name);
		void				set_nickname(const std::string &nickname);
		void				set_phone_number(const std::string &phone_number);
		void				set_darkest_secret(const std::string &darkest_secret);

		const std::string	&get_first_name(void) const;
		const std::string	&get_last_name(void) const;
		const std::string	&get_nickname(void) const;
		const std::string	&get_phone_number(void) const;
		const std::string	&get_darkest_secret(void) const;

		void				display() const;

	private:
		std::string	m_first_name;
		std::string	m_last_name;
		std::string	m_nickname;
		std::string	m_phone_number;
		std::string	m_darkest_secret;
};

#endif