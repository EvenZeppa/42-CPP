#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string newName);
	FragTrap(FragTrap& fragTrap);
	FragTrap& operator=(FragTrap& fragTrap);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys(void);
};