#include "FragTrap.hpp"

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " created" << std::endl;
}

FragTrap::FragTrap(FragTrap& fragTrap) : ClapTrap(fragTrap.name)
{
	std::cout << "FragTrap " << name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& fragTrap)
{
	std::cout << "FragTrap " << fragTrap.name << " assigned to " << name << std::endl;

	name = fragTrap.name;
	hitPoints = fragTrap.hitPoints;
	energyPoints = fragTrap.energyPoints;
	attackDamage = fragTrap.attackDamage;

	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << " causing " << attackDamage << " point" << (attackDamage > 1 ? "s" : "") << " of damage!" << std::endl;
	energyPoints -= 1;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}