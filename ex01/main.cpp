#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main() {
	PhoneBook	phoneBook;
	Contact		contact;

	contact.setFirstName("John 1234567");
	contact.setLastName("Doe");
	contact.setNickName("JD");
	contact.setPhoneNumber("1234567890");
	contact.setDarkestSecret("I am Batman");

	phoneBook.addContact(contact);

	contact.setFirstName("Jane");
	contact.setLastName("Doe");
	contact.setNickName("JD");
	contact.setPhoneNumber("0987654321");
	contact.setDarkestSecret("I am Batman");

	phoneBook.addContact(contact);

	phoneBook.printContacts();

	return 0;
}