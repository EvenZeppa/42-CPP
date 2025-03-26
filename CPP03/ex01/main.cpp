#include "ScavTrap.hpp"

int	main()
{
	ScavTrap scavTrap("st1");
	ScavTrap scavTrap2(scavTrap);
	ScavTrap scavTrap3("st2");
	scavTrap3 = scavTrap;

	// Tests d'attaque
	scavTrap.attack("enemy");
	scavTrap.attack("enemy2");

	// Tests de dégâts
	scavTrap.takeDamage(20);
	scavTrap.takeDamage(90); // Test de dépassement des points de vie

	// Tests de réparation
	scavTrap.beRepaired(10);
	scavTrap.beRepaired(20);

	// Test d'épuisement d'énergie
	for (int i = 0; i < 60; i++)
		scavTrap.attack("enemy"); // Devrait afficher un message d'énergie épuisée après plusieurs attaques

	// Test du mode garde
	scavTrap.guardGate();

	return (0);
}