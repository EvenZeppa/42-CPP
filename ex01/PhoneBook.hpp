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

	Contact	getContact(int index);
	int		getIndex() const;

	void	incrementIndex();
	void	addContact(Contact contact);
	void	printContacts();
};

#endif