#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// Test Bureaucrat functionality
	std::cout << "\033[0;31m" << "Creating Bureaucrats !!!" << "\033[0m" << std::endl;
	
	Bureaucrat john("John", 50);
	std::cout << john << std::endl;
	Bureaucrat jane("Jane", 150);
	std::cout << jane << std::endl;
	Bureaucrat jack("Jack", 1);
	std::cout << jack << std::endl;
	std::cout << std::endl;

	// Test Form functionality
	std::cout << "\033[0;31m" << "Creating Forms !!!" << "\033[0m" << std::endl;
	Form formA("Form A", 50, 100);
	std::cout << formA << std::endl;
	Form formB("Form B", 20, 30);
	std::cout << formB << std::endl;
	try {
		Form formC("Form C", 0, 0);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test signing forms
	std::cout << "\033[0;31m" << "Signing Forms !!!" << "\033[0m" << std::endl;
	try {
		formA.beSigned(john);
		formB.beSigned(jane);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test Bureaucrat and Form states
	std::cout << "\033[0;31m" << "Bureaucrat and Form states !!!" << "\033[0m" << std::endl;
	std::cout << john << std::endl;
	std::cout << jane << std::endl;
	std::cout << jack << std::endl;
	std::cout << formA << std::endl;
	std::cout << formB << std::endl;
	std::cout << std::endl;

    return 0;
}
