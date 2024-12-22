#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

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
	std::string	getFirstName()	const;
	std::string	getLastName()	const;
	std::string	getNickName()	const;
	std::string	getPhoneNumber()	const;
	std::string	getDarkestSecret()	const;

	// SETTERS
	void	setFirstName(std::string firstName);
	void	setLastName(std::string lastName);
	void	setNickName(std::string nickName);
	void	setPhoneNumber(std::string phoneNumber);
	void	setDarkestSecret(std::string darkestSecret);
};


#endif