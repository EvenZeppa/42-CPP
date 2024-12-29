#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : type(type)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria& aMateria) : type(aMateria.type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(AMateria& aMateria)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	type = aMateria.type;

	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}