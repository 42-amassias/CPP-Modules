#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &o);
		~Animal();

		Animal				&operator=(const Animal &o);

		void				makeSound(void) const;
		const std::string	&getType(void) const; 

	protected:
		std::string	m_type;
};

#endif