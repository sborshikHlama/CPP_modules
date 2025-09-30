#pragma once
#include <iosfwd>
#include <cmath>

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

	Fixed& operator=(const Fixed& rightStamp);
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;

	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	static const Fixed& max(const Fixed& a, const Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static Fixed& min(Fixed& a, Fixed& b);

	int getRawBits(void) const;
	void setRawBits(const int &value);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &obj);
