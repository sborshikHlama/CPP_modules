#pragma once
#include <iostream>
#define DEBUG 0

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& obj);
	~Animal();
	Animal& operator=(const Animal& rightStamp);
	virtual void makeSound() const;
	std::string getType() const;
};