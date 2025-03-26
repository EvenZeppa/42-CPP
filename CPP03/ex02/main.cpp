#include "FragTrap.hpp"

int	main()
{
	FragTrap fragTrap("ft1");
	FragTrap fragTrap2(fragTrap);
	FragTrap fragTrap3("ft2");
	fragTrap3 = fragTrap;

	// Tests d'attaque
	fragTrap.attack("enemy");
	fragTrap.attack("enemy2");

	// Tests de dégâts
	fragTrap.takeDamage(20);
	fragTrap.takeDamage(90); // Test de dépassement des points de vie

	// Tests de réparation
	fragTrap.beRepaired(10);
	fragTrap.beRepaired(20);

	// Test d'épuisement d'énergie
	for (int i = 0; i < 110; i++)
		fragTrap.attack("enemy"); // Devrait afficher un message d'énergie épuisée après plusieurs attaques

	// Test de la demande de high five
	fragTrap.highFivesGuys();

	return (0);
}