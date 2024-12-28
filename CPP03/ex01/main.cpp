#include "ScavTrap.hpp"

int	main()
{
	ScavTrap scavTrap("st1");
	ScavTrap scavTrap2(scavTrap);
	ScavTrap scavTrap3("st2");
	scavTrap3 = scavTrap;

	scavTrap.attack("enemy");
	scavTrap.guardGate();
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(3);
	
	return (0);
}