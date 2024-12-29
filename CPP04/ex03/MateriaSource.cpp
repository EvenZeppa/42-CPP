#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource& materiaSource)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materiaSource.inventory[i])
			inventory[i] = materiaSource.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource& materiaSource)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
		if (materiaSource.inventory[i])
			inventory[i] = materiaSource.inventory[i]->clone();
		else
			inventory[i] = nullptr;
	}

	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return (inventory[i]->clone());
	}
	return (nullptr);
}
