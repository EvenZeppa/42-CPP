#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    PresidentialPardonForm(PresidentialPardonForm& presidentialPardonForm);
    PresidentialPardonForm& operator=(PresidentialPardonForm& presidentialPardonForm);

    void doExecution() const;
};

#endif