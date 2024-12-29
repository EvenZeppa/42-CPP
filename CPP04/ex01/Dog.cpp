#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(Dog& dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = dog.type;
	brain = new Brain(*dog.brain);
}

Dog& Dog::operator=(Dog& dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	type = dog.type;
	delete brain;
	brain = new Brain(*dog.brain);

	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound()
{
	std::cout << "Wouaf wouaf !!!" << std::endl;
}