#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
	std::string		name;
	unsigned int	hitPoints = 10;
	unsigned int	energyPoints = 10;
	unsigned int	attackDamage = 0;
public:
	ClapTrap(std::string newName);
	ClapTrap(ClapTrap& clapTrap);
	ClapTrap& operator=(ClapTrap& clapTrap);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif