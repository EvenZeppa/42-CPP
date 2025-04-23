#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &src)
	: _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade) {}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		_signed = src._signed;
	}
	return *this;
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << form.getSignGrade() << ", Exec Grade: " << form.getExecGrade();
	return os;
}