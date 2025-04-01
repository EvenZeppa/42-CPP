#include "Character.hpp"

Character::Character(std::string name) : name(name)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(Character& character) : name(character.name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (character.inventory[i])
			inventory[i] = character.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(Character& character)
{
	std::cout << "Character assignation operator called" << std::endl;
	name = character.name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
		if (character.inventory[i])
			inventory[i] = character.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}

	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}

std::string const& Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
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

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4) {
		if (inventory[idx])
		{
			delete inventory[idx];
			inventory[idx] = NULL;
		}
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}