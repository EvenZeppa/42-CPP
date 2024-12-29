#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Animal* animals[10];
	for (int i = 0; i < 4; i++)
		animals[i] = new Dog();
	for (int i = 4; i < 8; i++)
		animals[i] = new Cat();
	for (int i = 8; i < 10; i++)
		animals[i] = new Animal();
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete animals[i];
	return (0);
}