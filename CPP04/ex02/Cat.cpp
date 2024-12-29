#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(Cat& cat) : AAnimal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = cat.type;
	brain = new Brain(*cat.brain);
}

Cat& Cat::operator=(Cat& cat)
{
	std::cout << "Cat assignation operator called" << std::endl;
	type = cat.type;
	brain = new Brain(*cat.brain);

	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound()
{
	std::cout << "Miaou miaou !!!" << std::endl;
}