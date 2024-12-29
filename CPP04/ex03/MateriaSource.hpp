#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	inventory[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource& materiaSource);
	MateriaSource& operator=(MateriaSource& materiaSource);
	~MateriaSource();

	void learnMateria(AMateria* m) override;
	AMateria* createMateria(std::string const& type) override;
};

#endif