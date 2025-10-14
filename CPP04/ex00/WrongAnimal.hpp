#pragma once
#include <iostream>
#define DEBUG 0

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal& rightStamp);
	void makeSound() const;
	std::string getType() const;
};
