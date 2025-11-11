#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand((unsigned)time(NULL));

	Bureaucrat b1("Le V", 150);
	Bureaucrat b2("EVNE LE GOAR", 1);

	ShrubberyCreationForm f1("f1");
	RobotomyRequestForm f2("f2");
	PresidentialPardonForm f3("f3");

	b2.signForm(f1);
	b2.signForm(f2);
	b2.signForm(f3);

	f1.execute(b2);
	f2.execute(b2);
	b2.executeForm(f3);
    return 0;
}
