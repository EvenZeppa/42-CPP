#include <iostream>

class Zombie
{
private:
	std::string name;

public:

	Zombie() : name("") {};
	Zombie(std::string zombieName) : name(zombieName) {};
	~Zombie();

	void	setName(std::string newName);

	void	announce(void) const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie*	zombieHorde( int N, std::string name );
