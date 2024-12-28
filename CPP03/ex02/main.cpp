#include "FragTrap.hpp"

int	main()
{
	FragTrap fragTrap("ft1");
	FragTrap fragTrap2(fragTrap);
	FragTrap fragTrap3("ft2");
	fragTrap3 = fragTrap;

	fragTrap.attack("enemy");
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(5);
	fragTrap.beRepaired(3);
	
	return (0);
}