#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8];
	int		i;

public:
	PhoneBook();

	void	incrementIndex();
	void	addContact(Contact contact);
	void	printContacts();
};

#endif