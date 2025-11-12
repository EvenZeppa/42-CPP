#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm* rrf;
	
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;
	delete rrf;

	rrf = someRandomIntern.makeForm("presidential pardon", "Bite");
	std::cout << *rrf;
	delete rrf;
    return 0;
}
