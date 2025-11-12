#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

struct TypeForm {
    std::string name;
    AForm* (*f)(const std::string&);
};

class Intern {
    public:
        Intern();
        ~Intern();

        Intern(const Intern& other);
        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& name, const std::string& target);
};

#endif