#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta;
	const Animal* j;
	const Animal* i;
	const WrongAnimal *wrong;
	const WrongAnimal *wrongCat;

	meta = new Animal();
	j = new Dog();
	i = new Cat();
	std::cout << "J Type: " << j->getType() << " " << std::endl;
	std::cout << "I Type: " << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete  meta;
	delete  j;
	delete  i;
	wrong = new WrongAnimal();
	wrongCat = new WrongCat();
	std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
	std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();
	delete  wrong;
	delete  wrongCat;
	return (0);
}