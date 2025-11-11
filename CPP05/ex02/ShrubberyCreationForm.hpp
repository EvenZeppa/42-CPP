#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(ShrubberyCreationForm& ShrubberyCreationForm);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm& ShrubberyCreationForm);

    void doExecution() const;
};

#endif