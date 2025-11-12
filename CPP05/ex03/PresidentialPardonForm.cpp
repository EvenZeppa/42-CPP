#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 145, 137), _target(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& presidentialPardonForm): AForm(presidentialPardonForm) {};

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& presidentialPardonForm) {
    if (this->_target != presidentialPardonForm._target)
        this->_target = presidentialPardonForm._target;
    return *this;
};

void PresidentialPardonForm::doExecution() const {
    std::cout << this->_target << " is pardoned by Zaphod Beeblebrox." << std::endl;
};

AForm* PresidentialPardonForm::create(const std::string& target) {
    return new PresidentialPardonForm(target);
};
