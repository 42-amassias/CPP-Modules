#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &o);
		virtual ~WrongAnimal(void);

		WrongAnimal			&operator=(const WrongAnimal &o);

		virtual void		makeSound(void) const;
		const std::string	&getType(void) const; 

	protected:
		std::string	m_type;
};

#endif