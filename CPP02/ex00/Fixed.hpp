#pragma once

class Fixed
{
private:
	int _value;
	static const int _fractional;
public:
	Fixed();
	Fixed(const Fixed &obj);
	~Fixed();
	Fixed& operator=(const Fixed &rightStamp);
	int getRawBits(void) const;
	void setRawBits(const int &value);
};
