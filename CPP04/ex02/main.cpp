#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	// Create a dog and a cat
	Dog dog;
	Cat cat;

	// AAnimal is abstract
	// AAnimal aAnimal;

	// Make the dog and the cat make a sound
	dog.makeSound();
	cat.makeSound();
	return (0);
}