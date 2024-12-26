#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
