#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void			add(const Contact &contact);
		void			display(void) const;

		size_t			get_contact_count(void) const;
		const Contact	&get(size_t index) const;

		static const size_t	max_contact_count = 8;
	private:
		size_t	m_contact_count;
		Contact	m_contacts[PhoneBook::max_contact_count];
};

#endif