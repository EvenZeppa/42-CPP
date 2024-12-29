#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat& cat) : Animal(cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = cat.type;
}

Cat& Cat::operator=(Cat& cat)
{
	std::cout << "Cat assignation operator called" << std::endl;
	type = cat.type;

	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "Miaou miaou !!!" << std::endl;
}