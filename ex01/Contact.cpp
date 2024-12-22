#include "Contact.hpp"

class Contact {
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact() :
		firstName(""),
		lastName(""),
		nickName(""),
		phoneNumber(""),
		darkestSecret("") {}
	
	// GETTERS
	std::string	getFirstName() const { return firstName; }
	std::string	getLastName() const { return lastName; }
	std::string	getNickName() const { return nickName; }
	std::string	getPhoneNumber() const { return phoneNumber; }
	std::string	getDarkestSecret() const { return darkestSecret; }

	// SETTERS
	void	setFirstName(std::string firstName) { this->firstName = firstName; }
	void	setLastName(std::string lastName) { this->lastName = lastName; }
	void	setNickName(std::string nickName) { this->nickName = nickName; }
	void	setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
	void	setDarkestSecret(std::string darkestSecret) { this->darkestSecret = darkestSecret; }
};