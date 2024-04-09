#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &o);
		~WrongAnimal();

		WrongAnimal				&operator=(const WrongAnimal &o);

		void				makeSound(void) const;
		const std::string	&getType(void) const; 

	protected:
		std::string	m_type;
};

#endif