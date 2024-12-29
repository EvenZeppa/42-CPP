#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog& dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = dog.type;
}

Dog& Dog::operator=(Dog& dog)
{
	std::cout << "Dog assignation operator called" << std::endl;
	type = dog.type;

	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Wouaf wouaf !!!" << std::endl;
}