#pragma once
#include <iostream>
#define DEBUG 1

class Animal
{
protected:
	std::string type;
	Animal();
public:
	Animal(const Animal& obj);
	virtual ~Animal();
	Animal& operator=(const Animal& rightStamp);
	virtual void makeSound() const;
	std::string getType() const;
};