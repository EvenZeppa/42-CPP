#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(AAnimal& animal);
	AAnimal& operator=(AAnimal& animal);
	virtual ~AAnimal();

	virtual void	makeSound() = 0;
};

#endif