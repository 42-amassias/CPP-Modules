#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &o);
		virtual ~Animal(void);

		Animal				&operator=(const Animal &o);

		virtual void		makeSound(void) const = 0;
		const std::string	&getType(void) const; 

	protected:
		std::string	m_type;
};

#endif