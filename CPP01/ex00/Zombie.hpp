#include <iostream>

class Zombie
{
private:
	std::string name;

public:

	Zombie(std::string zombieName) : name(zombieName) {};
	~Zombie();

	void	announce(void) const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
