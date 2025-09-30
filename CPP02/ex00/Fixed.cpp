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
	_value = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& rightStamp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = rightStamp.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(const int &value)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
