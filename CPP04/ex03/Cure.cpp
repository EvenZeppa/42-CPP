#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& cure) : AMateria(cure.type)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(Cure& cure)
{
	std::cout << "Cure assignation operator called" << std::endl;
	(void)cure;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}