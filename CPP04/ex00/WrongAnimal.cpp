#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	if (DEBUG)
		std::cout << "WrongAnimal constructor was called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "Copy constructor was called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	if (DEBUG)
		std::cout << "WrongAnimal destructor was called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rightStamp)
{
	this->type = rightStamp.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
