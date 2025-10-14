#pragma once

#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
public:
	WrongDog();
	~WrongDog();
	void makeSound() const;
};