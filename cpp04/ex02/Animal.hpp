#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	public:
		virtual ~Animal(void);

		Animal				&operator=(const Animal &o);

		virtual void		makeSound(void) const;
		const std::string	&getType(void) const; 

	protected:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &o);
		std::string	m_type;
};

#endif