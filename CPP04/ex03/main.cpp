#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	// Test MateriaSource functionality
	std::cout << "\033[0;31m" << "Creating MateriaSource !!!" << "\033[0m" << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	src->learnMateria(new Ice()); // Adding duplicate Materia
	std::cout << std::endl;
	src->learnMateria(new Cure()); // Filling inventory
	std::cout << std::endl;
	src->learnMateria(new Ice()); // Attempt to overfill inventory
	std::cout << std::endl;

	// Test Character functionality
	ICharacter* me = new Character("me");
	std::cout << std::endl;

	// Test equip functionality
	std::cout << "\033[0;31m" << "Equipping Materia !!!" << "\033[0m" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice"); // Attempt to equip more than 4 Materia
	me->equip(tmp);
	std::cout << std::endl;

	// Test unequip functionality
	std::cout << "\033[0;31m" << "Unequipping Materia !!!" << "\033[0m" << std::endl;
	me->unequip(1); // Unequip Cure
	me->unequip(4); // Attempt to unequip out-of-bounds index
	tmp = src->createMateria("cure");
	me->equip(tmp); // Equip Cure again after unequip
	std::cout << std::endl;

	// Test using Materia
	std::cout << "\033[0;31m" << "Using Materia !!!" << "\033[0m" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob); // Use Ice
	me->use(1, *bob); // Use Cure
	me->use(2, *bob); // Use Ice
	me->use(3, *bob); // Use Cure
	me->use(4, *bob); // Attempt to use out-of-bounds index
	std::cout << std::endl;

	// Clean up
	std::cout << "\033[0;31m" << "Cleaning up !!!" << "\033[0m" << std::endl;
	delete bob;
	delete me;
	delete src;

	return 0;
}