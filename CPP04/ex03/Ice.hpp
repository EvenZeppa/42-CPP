#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice& ice);
	Ice& operator=(Ice& ice);
	~Ice() override;

	AMateria* clone() const override;
	void use(ICharacter& target) override;
};

#endif
