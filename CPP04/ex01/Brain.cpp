#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain& brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
}

Brain& Brain::operator=(Brain& brain)
{
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];

	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}