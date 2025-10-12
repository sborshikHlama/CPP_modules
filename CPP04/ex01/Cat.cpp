#include "Cat.hpp"

// Tries to call the default construcot of the parent
Cat::Cat()
{
	this->type = "Cat";
	if (DEBUG)
		std::cout << "Cat constructor was called" << std::endl;
};

Cat::~Cat()
{
	if (DEBUG)
		std::cout << "Cat destructor was called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes sound: Meow" << std::endl;
}
