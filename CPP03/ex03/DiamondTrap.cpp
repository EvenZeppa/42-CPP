#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string newName)
	: ClapTrap(newName + "_clap_name"),
	ScavTrap(newName + "_scav_name"),
	FragTrap(newName + "_frag_name"),
	name(newName)
{
	std::cout << "DiamondTrap " << name << " created" << std::endl;

	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap& diamondTrap)
	: ClapTrap(diamondTrap.name + "_clap_name"),
	ScavTrap(diamondTrap.name),
	FragTrap(diamondTrap.name),
	name(diamondTrap.name)
{
	std::cout << "DiamondTrap " << name << " copied" << std::endl;	

	hitPoints = diamondTrap.hitPoints;
	energyPoints = diamondTrap.energyPoints;
	attackDamage = diamondTrap.attackDamage;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& diamondTrap)
{
	std::cout << "DiamondTrap " << diamondTrap.name << " assigned to " << name << std::endl;

	name = diamondTrap.name;
	hitPoints = diamondTrap.hitPoints;
	energyPoints = diamondTrap.energyPoints;
	attackDamage = diamondTrap.attackDamage;

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "DiamondTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << name << " attacks " << target << " causing " << attackDamage << " point" << (attackDamage > 1 ? "s" : "") << " of damage!" << std::endl;
	energyPoints -= 1;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}