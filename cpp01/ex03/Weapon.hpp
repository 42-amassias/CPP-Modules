#ifndef VIOLENCE_HPP
# define VIOLENCE_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(const std::string &type);
		~Weapon(void);

		const std::string	&getType(void) const;
		void				setType(const std::string &type);

	private:
		std::string	m_type;
};

#endif
