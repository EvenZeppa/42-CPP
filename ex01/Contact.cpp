#include "Contact.hpp"

Contact::Contact() :
	firstName(""),
	lastName(""),
	nickName(""),
	phoneNumber(""),
	darkestSecret("") {}

std::string	Contact::getFirstName() const { return firstName; }
std::string	Contact::getLastName() const { return lastName; }
std::string	Contact::getNickName() const { return nickName; }
std::string	Contact::getPhoneNumber() const { return phoneNumber; }
std::string	Contact::getDarkestSecret() const { return darkestSecret; }

void	Contact::setFirstName(std::string firstName) { this->firstName = firstName; }
void	Contact::setLastName(std::string lastName) { this->lastName = lastName; }
void	Contact::setNickName(std::string nickName) { this->nickName = nickName; }
void	Contact::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void	Contact::setDarkestSecret(std::string darkestSecret) { this->darkestSecret = darkestSecret; }

int	Contact::checkNotEmpty() const {
	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty())
		return 0;
	return 1;
}

void	Contact::printContact() const {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nick name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}