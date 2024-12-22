// #include "PhoneBook.hpp"
#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8];
	int		i;

public:
	PhoneBook() : i(0) {}

	void	incremetIndex() {
		this->i++;
		if (this->i == 8)
			this->i = 0;
	}

	void	addContact(Contact contact) {
		contacts[this->i] = contact;
		this->incremetIndex();
	}
};
