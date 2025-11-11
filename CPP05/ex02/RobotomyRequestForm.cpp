#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 145, 137), _target(target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& robotomyRequestForm): AForm(robotomyRequestForm) {};

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& robotomyRequestForm) {
    if (this->_target != robotomyRequestForm._target)
        this->_target = robotomyRequestForm._target;
    return *this;
};

void RobotomyRequestForm::doExecution() const {
    std::cout << "GLOU-GLOU !!! GLOU-GLOU !!!" << std::endl;
    if ((std::rand() % 2) == 0) {
        std::cout << this->_target << " is robotomized successfully" << std::endl;
    } else {
        std::cout << this->_target << " is robotomized failed" << std::endl;
    } 
};