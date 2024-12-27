#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
	this->_value = value;
	this->_value <<= Fixed::_bits;
}

Fixed::Fixed(float value)
{
	int		integer_part = roundf(value);
	float	decimal_part;
	int		sizeDecimal = 1;
	int		final;

	if (integer_part == roundf(value + 0.5))
		integer_part--;
	decimal_part = value - integer_part;
	
	this->_value = integer_part;
	this->_value <<= Fixed::_bits;
	
	for (int i = ((1 << Fixed::_bits) - 1); i >= 10; i /= 10)
		sizeDecimal *= 10;

	final = roundf(decimal_part * sizeDecimal);

	this->_value += final;	
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignement called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_value > fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_value < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_value >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_value <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_value == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_value != fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	Fixed result;

	result.setRawBits(this->_value + fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	Fixed result;

	result.setRawBits(this->_value - fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	float fResult = this->toFloat() * fixed.toFloat();
	Fixed result(fResult);

	return result;
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	float fResult = this->toFloat() / fixed.toFloat();
	Fixed result(fResult);

	return result;
}

Fixed&	Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed&	Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	if (fixed._value & ((1 << fixed._bits) - 1))
		os << fixed.toFloat();
	else
		os << fixed.toInt();
	return os;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return (roundf(this->toFloat()));
}

float Fixed::toFloat(void) const
{
	int integer_part = this->_value >> Fixed::_bits;
	int decimal_part = this->_value & ((1 << Fixed::_bits) - 1);
	int sizeDecimal = 1;

	if (decimal_part == 0)
		return (integer_part);
	
	for (int i = ((1 << Fixed::_bits) - 1); i >= 10; i /= 10)
		sizeDecimal *= 10;

	return (static_cast<float>(integer_part) + static_cast<float>(decimal_part) / sizeDecimal);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}