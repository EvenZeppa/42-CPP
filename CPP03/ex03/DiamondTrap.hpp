#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	name;
public:
	DiamondTrap(std::string newName);
	DiamondTrap(DiamondTrap& diamondTrap);
	DiamondTrap& operator=(DiamondTrap& diamondTrap);
	~DiamondTrap();

	void attack(const std::string& target);
	void whoAmI();
};

#endif