#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure& cure);
	Cure& operator=(Cure& cure);
	~Cure() override;

	AMateria* clone() const override;
	void use(ICharacter& target) override;
};

#endif