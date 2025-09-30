#pragma once
#include <iosfwd>

class Fixed
{
private:
	int _value;
	static const int _fractional;
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int &ivalue);
	Fixed(const float &fvalue);
	~Fixed();
	Fixed& operator=(const Fixed &rightStamp);
	int getRawBits(void) const;
	void setRawBits(const int &value);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &obj);
