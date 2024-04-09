#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat :
	public Animal
{
	public:
		Cat(void);
		Cat(const Cat &o);
		~Cat(void);

		Cat		&operator=(const Cat &o);

		void	makeSound(void) const;
	
	private:
		Brain	*m_brain;
};

#endif