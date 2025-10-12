#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	if (DEBUG)
		std::cout << "Animal constructor was called" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	this->type = obj.type;
	if (DEBUG)
		std::cout << "Copy constructor was called" << std::endl;
}

Animal::~Animal()
{
	if (DEBUG)
		std::cout << "Destructor was called" << std::endl;
}

Animal& Animal::operator=(const Animal& rightStamp)
{
	this->type = rightStamp.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}