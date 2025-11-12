#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void) other;
}

Intern& Intern::operator=(const Intern& other) {
    (void) other;
    return *this;
}

static TypeForm TypeForms[] = {
    {"robotomy request", &RobotomyRequestForm::create},
    {"presidential pardon", &PresidentialPardonForm::create},
    {"shrubbery creation", &ShrubberyCreationForm::create}
};

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    AForm *form;
    
    for (size_t i = 0; i < (sizeof(TypeForms) / sizeof(TypeForm)); i++)
    {
        if (TypeForms[i].name == name)
        {
            form = TypeForms[i].f(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
        }
    }

    return form;
}