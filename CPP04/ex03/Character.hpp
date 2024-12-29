#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria*	inventory[4];
public:
	Character(std::string name);
	Character(Character& character);
	Character& operator=(Character& character);
	~Character() override;

	std::string const& getName() const override;
	void equip(AMateria* m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};

#endif