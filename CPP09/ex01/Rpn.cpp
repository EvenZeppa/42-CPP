#include "Rpn.hpp"

binary RPN::_binaryAccess() {
	if (_stack.size() <= 1)
		throw RPN::StackIsEmptyException();
	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();

	return binary(left, right);
}

RPN::RPN() : _str("") {}

RPN::RPN(const std::string& str) : _str(str) {}

// #TODO tester si on doit refill la stack au lieu de la copier
RPN::RPN(const RPN& other) : _stack(other._stack), _str(other._str) {
	(void) other;
}

RPN& RPN::operator=(const RPN& other) {
	(void) other;
	return *this;
}

RPN::~RPN() {}

void RPN::str(const std::string& str) {
	_str = str;
}

std::string RPN::str() {
	return _str;
}

void RPN::push(int n) {
	_stack.push(n);
}

int RPN::pop() {
	if (_stack.size() == 0)
		throw RPN::StackIsEmptyException();
	int n = _stack.top();
	_stack.pop();
	return n;
}

void RPN::clear() {
	while (_stack.size() > 0)
		_stack.pop();
}

void RPN::process(const std::string& str) {
	(void) str;
}

int RPN::result() {
	if (_stack.size() == 0)
		throw RPN::StackIsEmptyException();
	if (_stack.size() > 1)
		throw RPN::InvalidResultStackException();
	return _stack.top();
}

std::ostream& operator<<(std::ostream &os, const RPN& rpn) {
	(void) rpn;
	return os;
}

void RPN::sum() {
	binary binary = _binaryAccess();

	_stack.push(binary.first + binary.second);
}

void RPN::sub() {
	binary binary = _binaryAccess();

	_stack.push(binary.first - binary.second);
}

void RPN::mul() {
	binary binary = _binaryAccess();

	_stack.push(binary.first * binary.second);
}

void RPN::div() {
	binary binary = _binaryAccess();

	if (binary.second == 0)
		throw RPN::DivideByZeroException();

	_stack.push(binary.first / binary.second);
}

const char* RPN::InvalidTypeException::what() const throw() {
	return "Invalid type";
}

const char* RPN::DivideByZeroException::what() const throw() {
	return "Divide by zero";
}

const char* RPN::InvalidResultStackException::what() const throw() {
	return "Invalid result stack";
}

const char* RPN::InvalidBinaryStackException::what() const throw() {
	return "Invalid binary stack";
}

const char* RPN::StackIsEmptyException::what() const throw() {
	return "Stack is empty";
}