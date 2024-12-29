#include "Animal.hpp"


Animal::Animal() : type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal& animal) : type(animal.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(Animal& animal)
{
	std::cout << "Animal assignation operator called" << std::endl;
	type = animal.type;

	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound()
{
	std::cout << "Animal make a sound" << std::endl;
}
