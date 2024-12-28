#include <iostream>
#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string newName) : name(newName)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& clapTrap) : name(clapTrap.name), hitPoints(clapTrap.hitPoints), energyPoints(clapTrap.energyPoints), attackDamage(clapTrap.attackDamage)
{
	std::cout << "ClapTrap " << name << " copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap& clapTrap)
{
	std::cout << "ClapTrap " << clapTrap.name << " assigned to " << name << std::endl;

	name = clapTrap.name;
	hitPoints = clapTrap.hitPoints;
	energyPoints = clapTrap.energyPoints;
	attackDamage = clapTrap.attackDamage;

	return (*this);
}

ClapTrap::~ClapTrap()
{
	if (energyPoints > 0)
		std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " point" << (attackDamage > 1 ? "s" : "") << " of damage!" << std::endl;
	energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
	{
		std::cout << "ClapTrap " << name << " takes " << hitPoints << " point" << (hitPoints > 1 ? "s" : "") << " of damage!" << std::endl;
		hitPoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " point" << (amount > 1 ? "s" : "") << " of damage!" << std::endl;
		hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " is repaired for " << amount << " point" << (amount > 1 ? "s" : "") << "!" << std::endl;
	hitPoints += amount;
	energyPoints -= 1;
}