#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog :
	public Animal
{
	public:
		Dog(void);
		Dog(const Dog &o);
		~Dog(void);

		Dog		&operator=(const Dog &o);

		void	makeSound(void) const;
	
	private:
		Brain	*m_brain;
};

#endif