#include <cstring>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main() {
	PhoneBook	phoneBook;
	Contact		contact;
	char		input[32];

	contact.setFirstName("John");
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

	// Wait for ADD, SEARCH or EXIT command
	while (1) {
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		std::cin >> input;
		if (std::cin.eof() || !std::strcmp(input, "EXIT"))
			break;
		else if (!std::strcmp(input, "ADD")) {
			contact = Contact();
			
			std::cout << "First name: ";
			std::cin >> input;
			contact.setFirstName(input);

			std::cout << "Last name: ";
			std::cin >> input;
			contact.setLastName(input);
			
			std::cout << "Nick name: ";
			std::cin >> input;
			contact.setNickName(input);

			std::cout << "Phone number: ";
			std::cin >> input;
			contact.setPhoneNumber(input);

			std::cout << "Darkest secret: ";
			std::cin >> input;
			contact.setDarkestSecret(input);
			if (contact.checkNotEmpty())
				phoneBook.addContact(contact);
		}
		else if (!std::strcmp(input, "SEARCH")) {
			phoneBook.printContacts();
			std::cout << "Enter index: ";
			std::cin >> input;
			if (std::atoi(input) < 1 || std::atoi(input) > phoneBook.getIndex()) {
				std::cout << "Invalid index" << std::endl;
				continue;
			}
			phoneBook.getContact(std::atoi(input) - 1).printContact();
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}

	// phoneBook.printContacts();

	return 0;
}