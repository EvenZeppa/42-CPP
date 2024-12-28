#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string newName);
	ScavTrap(ScavTrap& scavTrap);
	ScavTrap& operator=(ScavTrap& scavTrap);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();
};

#endif