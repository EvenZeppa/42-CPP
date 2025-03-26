#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice& ice);
	Ice& operator=(Ice& ice);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
