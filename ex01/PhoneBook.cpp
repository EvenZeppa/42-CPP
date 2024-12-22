#include "PhoneBook.hpp"

static std::string truncateWithDot(const std::string& str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

PhoneBook::PhoneBook() : i(0) {}

void	PhoneBook::incrementIndex() {
	this->i++;
	if (this->i == 8)
		this->i = 0;
}

void	PhoneBook::addContact(Contact contact) {
	contacts[this->i] = contact;
	this->incrementIndex();
}

void	PhoneBook::printContacts() {
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int j = 0; j < 8; j++) {
		if (!contacts[j].getFirstName().empty()) {
			std::cout << std::setw(10) << j + 1 << "|";
			std::cout << std::setw(10) << truncateWithDot(contacts[j].getFirstName()) << "|";
			std::cout << std::setw(10) << truncateWithDot(contacts[j].getLastName()) << "|";
			std::cout << std::setw(10) << truncateWithDot(contacts[j].getNickName()) << std::endl;
		}
	}
}
