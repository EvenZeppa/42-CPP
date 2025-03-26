#include "ClapTrap.hpp"

int	main()
{
	ClapTrap clapTrap("cp1");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3("cp2");
	clapTrap3 = clapTrap;

	// Tests d'attaque
	clapTrap.attack("enemy");
	clapTrap.attack("enemy2");

	// Tests de dégâts
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(10); // Test de dépassement des points de vie

	// Tests de réparation
	clapTrap.beRepaired(3);
	clapTrap.beRepaired(5);

	// Test d'épuisement d'énergie
	for (int i = 0; i < 10; i++)
		clapTrap.attack("enemy"); // Devrait afficher un message d'énergie épuisée après plusieurs attaques

	return (0);
}