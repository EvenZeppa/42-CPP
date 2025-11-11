#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(std::string name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	std::string getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const;
	virtual void doExecution() const = 0;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};

	class FormAlreadySignedException : public std::exception {
		public:
			const char* what() const throw();
	};
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _execGrade;
};
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif