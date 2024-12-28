#include "ClapTrap.hpp"

int	main()
{
	ClapTrap clapTrap("cp1");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3("cp2");
	clapTrap3 = clapTrap;

	clapTrap.attack("enemy");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	return (0);
}