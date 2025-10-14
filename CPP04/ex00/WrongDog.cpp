#include "WrongDog.hpp"

// Tries to call the default construcot of the parent
WrongDog::WrongDog()
{
	this->type = "WrongDog";
	if (DEBUG)
		std::cout << "WrongDog constructor was called" << std::endl;
};

WrongDog::~WrongDog()
{
	if (DEBUG)
		std::cout << "WrongDog destructor was called" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "WrongDog makes sound: Bark" << std::endl;
}
