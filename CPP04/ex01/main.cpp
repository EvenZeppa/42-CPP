#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	// Array of 10 animals
	Animal*	animals[10];

	// 5 dogs and 5 cats
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Make all animals make a sound
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	// Delete all animals
	for (int i = 0; i < 10; i++)
		delete animals[i];
	
	return (0);
}