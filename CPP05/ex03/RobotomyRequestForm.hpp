#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <time.h>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    RobotomyRequestForm(RobotomyRequestForm& RobotomyRequestForm);
    RobotomyRequestForm& operator=(RobotomyRequestForm& RobotomyRequestForm);

	static AForm* create(const std::string& target);
    void doExecution() const;
};

#endif