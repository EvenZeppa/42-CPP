#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_isSigned)
		throw FormAlreadySignedException();
	_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm: " << form.getName() << ", Sign Grade: " << form.getSignGrade()
	   << ", Exec Grade: " << form.getExecGrade() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

const char* AForm::FormAlreadySignedException::what() const throw() {
	return "Form is already signed!";
}

