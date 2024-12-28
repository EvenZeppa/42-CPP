#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& scavTrap) : ClapTrap(scavTrap.name)
{
	std::cout << "ScavTrap " << name << " copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& scavTrap)
{
	std::cout << "ScavTrap " << scavTrap.name << " assigned to " << name << std::endl;

	name = scavTrap.name;
	hitPoints = scavTrap.hitPoints;
	energyPoints = scavTrap.energyPoints;
	attackDamage = scavTrap.attackDamage;

	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << " causing " << attackDamage << " point" << (attackDamage > 1 ? "s" : "") << " of damage!" << std::endl;
	energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " has entered in Gate keeper mode" << std::endl;
}