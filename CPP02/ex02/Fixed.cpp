#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractional = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = obj._value;
}

Fixed::Fixed(const int &ivalue)
{
	_value = ivalue << _fractional;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &fvalue)
{
	_value = static_cast<int>(roundf(fvalue * (1 << _fractional)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rightStamp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = rightStamp.getRawBits();
	return (*this);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value++;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value--;
	return (temp);
}

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(const int &value)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = value;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fractional));
}

int Fixed::toInt(void) const
{
	return (_value >> _fractional);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
