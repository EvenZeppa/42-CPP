#pragma once

#include <string>
#include <stack>
#include <ostream>
#include <stdexcept>

typedef std::pair<int, int> binary;

class RPN {
private:
	std::stack<int> _stack;
	std::string _str;

	binary _binaryAccess();
public:
	RPN();
	RPN(const std::string& str);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void str(const std::string& str);
	std::string str();

	void push(int n);
	int pop();

	void clear();

	void process(const std::string& str);
	int result();

	friend std::ostream& operator<<(std::ostream &os, const RPN& rpn);

	void sum();
	void sub();
	void mul();
	void div();

	class InvalidTypeException : public std::exception {
		public:
			const char* what() const throw();
	};

	class DivideByZeroException : public std::exception {
		public:
			const char* what() const throw();
	};

	class InvalidResultStackException : public std::exception {
		public:
			const char* what() const throw();
	};

	class InvalidBinaryStackException : public std::exception {
		public:
			const char* what() const throw();
	};

	class StackIsEmptyException : public std::exception {
		public:
			const char* what() const throw();
	};
};