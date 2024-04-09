#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*j;
	const Animal	*i;

	j = new Dog();
	i = new Cat();
	delete j;//should not create a leak
	delete i;

	Dog basic;
	{
		Dog tmp = basic;
	}

	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	for (size_t i = 0; i < 4; ++i)
		delete animals[i];
	return (0);
}