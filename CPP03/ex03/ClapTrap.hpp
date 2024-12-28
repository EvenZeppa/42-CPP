#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string		name;
	unsigned int	hitPoints = 10;
	unsigned int	energyPoints = 10;
	unsigned int	attackDamage = 0;
public:
	ClapTrap(std::string newName);
	ClapTrap(ClapTrap& clapTrap);
	ClapTrap& operator=(ClapTrap& clapTrap);
	virtual ~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
