#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain*	brain;
public:
	Dog();
	Dog(Dog& dog);
	Dog& operator=(Dog& dog);
	~Dog();

	void	makeSound();
};

#endif