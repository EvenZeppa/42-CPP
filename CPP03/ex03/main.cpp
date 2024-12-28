#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	std::cout << "Testing ClapTrap:" << std::endl;
	ClapTrap ct1("ct1");
	ct1.attack("enemy");
	ct1.takeDamage(5);
	ct1.beRepaired(3);
	ct1.takeDamage(10);
	ct1.beRepaired(3);

	std::cout << "\nTesting ScavTrap:" << std::endl;
	ScavTrap st1("st1");
	st1.attack("enemy");
	st1.takeDamage(5);
	st1.beRepaired(3);
	st1.guardGate();
	st1.takeDamage(10);
	st1.beRepaired(3);

	std::cout << "\nTesting FragTrap:" << std::endl;
	FragTrap ft1("ft1");
	ft1.attack("enemy");
	ft1.takeDamage(5);
	ft1.beRepaired(3);
	ft1.highFivesGuys();
	ft1.takeDamage(10);
	ft1.beRepaired(3);

	std::cout << "\nTesting DiamondTrap:" << std::endl;
	DiamondTrap dt1("dt1");
	DiamondTrap dt2("dt2");
	DiamondTrap dt3(dt2);
	dt2 = dt1;
	dt1.attack("enemy");
	dt1.takeDamage(5);
	dt1.beRepaired(3);
	dt1.whoAmI();
	dt1.takeDamage(10);
	dt1.beRepaired(3);

	return (0);
}