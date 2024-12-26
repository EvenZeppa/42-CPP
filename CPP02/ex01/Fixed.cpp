#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	this->_value = (value << this->_bits);
}

Fixed::Fixed(float value)
{
	this->_value = value * (1 << this->_bits);
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignement called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return (roundf(this->toFloat()));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_value) / (1 << this->_bits);
}