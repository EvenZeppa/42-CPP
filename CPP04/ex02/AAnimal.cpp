#include "AAnimal.hpp"


AAnimal::AAnimal() : type("")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal& AAnimal) : type(AAnimal.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal& AAnimal)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	type = AAnimal.type;

	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}
